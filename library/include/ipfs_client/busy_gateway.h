#ifndef IPFS_BUSY_GATEWAY_H_
#define IPFS_BUSY_GATEWAY_H_

#include <vocab/raw_ptr.h>

#include <memory>
#include <string>

namespace {
struct TestParams;
}

namespace ipfs {
class DagListener;
class Gateway;
class Gateways;
class ContextApi;
class Scheduler;
class BusyGateway {
 public:
  BusyGateway(BusyGateway const&) = delete;
  BusyGateway(BusyGateway&&);
  ~BusyGateway();
  Gateway& operator*();
  Gateway* operator->();
  Gateway const* operator->() const;
  Gateway* get();
  explicit operator bool() const;
  void reset();
  bool operator==(BusyGateway const&) const;

  void Success(Gateways&, std::shared_ptr<ContextApi>);
  void Failure(Gateways&, std::shared_ptr<ContextApi>);

  std::string const& task() const { return suffix_; }
  std::string url() const { return prefix_ + suffix_; }

  static void TestAccess(TestParams*);

 private:
  friend class Scheduler;
  BusyGateway(std::string, std::string, Scheduler*);

  std::string prefix_;
  std::string suffix_;
  raw_ptr<Scheduler> scheduler_;
  std::size_t maybe_offset_;
};

}  // namespace ipfs

#endif
