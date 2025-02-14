#include <ipfs_client/gateways.h>

#include <ipfs_client/context_api.h>

#include "log_macros.h"

#include <algorithm>
#include <string>
#include <sstream>

using namespace std::string_literals;

ipfs::Gateways::Gateways()
    : random_engine_{std::random_device{}()}, dist_{0.01} {
  auto gws = DefaultGateways();
  for (auto [k, v] : gws) {
    known_gateways_[k] = v;
  }
}
ipfs::Gateways::~Gateways() {}

auto ipfs::Gateways::GenerateList() -> GatewayList {
  GatewayList result;
  for (auto [k, v] : known_gateways_) {
    result.push_back({k, v + dist_(random_engine_)});
  }
  std::sort(result.begin(), result.end());
  return result;
}

void ipfs::Gateways::promote(std::string const& key) {
  auto it = known_gateways_.find(key);
  if (known_gateways_.end() == it) {
    LOG(ERROR) << "Can't promote (" << key
               << ") because I don't know that one.";
  } else {
    auto l = known_gateways_.at(key)++;
    if (l % (++up_log_ / 2) <= 9) {
      LOG(INFO) << "Promote(" << key << ")";
    }
  }
}
void ipfs::Gateways::demote(std::string const& key) {
  auto it = known_gateways_.find(key);
  if (known_gateways_.end() == it) {
    VLOG(1) << "Can't demote " << key << " as I don't have that gateway.";
  } else if (it->second) {
    if (it->second-- % 3 == 0) {
      LOG(INFO) << "Demote(" << key << ") to " << it->second;
    }
  } else {
    LOG(INFO) << "Demoted(" << key << ") for the last time - dropping.";
    known_gateways_.erase(it);
  }
}

void ipfs::Gateways::AddGateways(std::vector<std::string> v) {
  LOG(INFO) << "AddGateways(" << v.size() << ')';
  for (auto& ip : v) {
    std::string prefix{"http://"};
    prefix.append(ip);
    prefix.push_back('/');
    if (known_gateways_.insert({prefix, 99}).second) {
      VLOG(1) << "Adding discovered gateway " << prefix;
    }
  }
}

std::vector<std::pair<std::string, int>> ipfs::Gateways::DefaultGateways() {
  auto* ovr = std::getenv("IPFS_GATEWAY");
  if (ovr && *ovr) {
    std::istringstream user_override{ovr};
    std::vector<std::pair<std::string, int>> result;
    std::string gw;
    while (user_override >> gw) {
      if ( gw.empty() ) {
        continue;
      }
      if ( gw.back() != '/' ) {
        gw.push_back('/');
      }
      result.emplace_back( gw, 0 );
    }
    auto N = static_cast<int>(result.size());
    for (auto i = 0; i < N; ++i) {
      auto& r = result[i];
      r.second = N - i;
      LOG(INFO) << "User-specified gateway: " << r.first << '=' << r.second;
    }
    return result;
  }
  return {{"http://localhost:8080/"s, 912},
          {"https://ipfs.io/"s, 909},
          {"https://gateway.ipfs.io/"s, 904},
          {"https://jcsl.hopto.org/"s, 902},
          {"https://dweb.link/"s, 899},
          {"https://ipfs.joaoleitao.org/"s, 896},
          {"https://ipfs.jpu.jp/"s, 321},
          {"https://gateway.pinata.cloud/"s, 304},
          {"https://jorropo.net/"s, 303},
          {"https://ipfs.runfission.com/"s, 300},
          {"https://nftstorage.link/"s, 285},
          {"https://w3s.link/"s, 262},
          {"https://ipfs.scalaproject.io/"s, 63},
          {"https://ipfs.fleek.co/"s, 63},
          {"https://ipfs.soul-network.com/"s, 58},
          {"https://permaweb.eu.org/"s, 56},
          {"https://hardbin.com/"s, 45},
          {"https://storry.tv/"s, 35},
          {"https://ipfs-gateway.cloud/"s, 13},
          {"https://ipfs.storry.tv/"s, 4},
          {"https://ipfs.anonymize.com/"s, 0}};
}
