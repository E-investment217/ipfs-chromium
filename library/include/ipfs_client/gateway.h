#ifndef CHROMIUM_IPFS_GATEWAY_H_
#define CHROMIUM_IPFS_GATEWAY_H_

#include "vocab/flat_mapset.h"

#include <string>

namespace ipfs {
class Gateway {
  std::string prefix_;
  flat_set<std::string> failed_requests_;
  unsigned priority_;
  std::string tasked_with_;

 public:
  Gateway(std::string url_prefix, unsigned priority);
  Gateway(Gateway const&);
  ~Gateway();

  std::string const& url_prefix() const;
  std::string url() const;
  std::string const& current_task() const;

  bool accept(std::string const& suffix);
  void MakeAvailable();
  void failed();
  bool PreviouslyFailed(std::string const& suffix) const;

  bool operator<(Gateway const&) const;
};

}  // namespace ipfs

#endif  // CHROMIUM_IPFS_GATEWAY_H_
