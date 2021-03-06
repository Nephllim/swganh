
#ifndef SWGANH_APP_SWGANH_APP_H_
#define SWGANH_APP_SWGANH_APP_H_

#include <list>
#include <memory>
#include <string>
#include <vector>

#include <boost/asio/deadline_timer.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/thread.hpp>
#include <tbb/atomic.h>

#include "anh/app/app_interface.h"
#include "anh/service/service_directory.h"

namespace anh {
namespace app {
class KernelInterface;
}}  // namespace anh::app

namespace swganh {
namespace app {

class SwganhKernel;

class SwganhApp : public anh::app::AppInterface, private boost::noncopyable {
public:    
    SwganhApp();
    ~SwganhApp();

    void Initialize(int argc, char* argv[]);

    void Start();

    void Stop();

    bool IsRunning();

    std::shared_ptr<anh::app::KernelInterface> GetAppKernel();

private:
    void LoadAppConfig_(int argc, char* argv[]);
    void LoadPlugins_(std::vector<std::string> plugins);
    void LoadCoreServices_();

    void CleanupServices_();

    void GalaxyStatusTimerHandler_(const boost::system::error_code& e,
        std::shared_ptr<boost::asio::deadline_timer> timer, int delay_in_secs);
    
    std::list<std::shared_ptr<boost::thread>> io_threads_;
    std::shared_ptr<SwganhKernel> kernel_;
    tbb::atomic<bool> running_;
    bool initialized_;
};

}}  // namespace swganh::app

#endif  // SWGANH_APP_SWGANH_APP_H_
