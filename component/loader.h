#ifndef COMPONENTS_IPFS_URL_LOADER_H_
#define COMPONENTS_IPFS_URL_LOADER_H_ 1

#include "ipfs_client/scheduler.h"

#include "base/debug/debugging_buildflags.h"
#include "services/network/public/cpp/resource_request.h"
#include "services/network/public/mojom/url_loader.mojom.h"
#include "mojo/public/cpp/bindings/receiver_set.h"
#include "mojo/public/cpp/system/data_pipe.h"

namespace network::mojom {
  class URLLoaderFactory;
}
namespace network {
  class SimpleURLLoader;
}

namespace ipfs {

  class Loader final : public network::mojom::URLLoader {
    void FollowRedirect(
        std::vector<std::string> const& removed_headers
      , net::HttpRequestHeaders  const& modified_headers
      , net::HttpRequestHeaders  const& modified_cors_exempt_headers
      , absl::optional<::GURL>   const& new_url
      ) override;
    void SetPriority(net::RequestPriority priority, int32_t intra_priority_value) override;
    void PauseReadingBodyFromNet() override;
    void ResumeReadingBodyFromNet() override;

  public:
    explicit Loader(network::mojom::URLLoaderFactory* handles_http,GatewayList&& initial);
    ~Loader() override;

    using ptr = std::shared_ptr<Loader>;

    // Passed as the RequestHandler for
    // Interceptor::MaybeCreateLoader.
    static void StartRequest(
        ptr
      , network::ResourceRequest const& resource_request
      , mojo::PendingReceiver<network::mojom::URLLoader> receiver
      , mojo::PendingRemote<network::mojom::URLLoaderClient> client
      );

  private:
      using RequestHandle = std::unique_ptr<network::SimpleURLLoader>;

      mojo::Receiver<network::mojom::URLLoader> receiver_{this};
      mojo::Remote<network::mojom::URLLoaderClient> client_;
      network::mojom::URLLoaderFactory* lower_loader_factory_;
      mojo::ScopedDataPipeProducerHandle pipe_prod_ = {};
      mojo::ScopedDataPipeConsumerHandle pipe_cons_ = {};
      Scheduler sched_;
      std::vector<std::pair<BusyGateway,RequestHandle>> gateway_requests_;

      void startup( ptr, std::string requested_path, unsigned concurrent_requests = 10 );
      bool start_gateway_request( ptr, std::string requested_path );
      bool start_gateway_request( ptr, GatewayList& free_gws, GatewayList& busy_gws, std::string requested_path );
      void on_gateway_response(ptr, std::string requested_path, std::size_t, std::unique_ptr<std::string>);
      bool handle_response( Gateway* gw, network::SimpleURLLoader* gw_req, std::string* body );
  };

}

#endif
