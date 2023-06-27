#include "resource_provider_client_server.h"
#include <thread>
#include <chrono>

int main()
{
    // 启动 ResourceProviderClientServer
    ResourceProviderClientServer resourceProvider;
    int resourceProviderPort = 9090;

    // 如果 resourceProvider.run 方法已经包含一个监听循环，那么下面的无限循环是不必要的
    resourceProvider.run(resourceProviderPort);

    // 如果 resourceProvider.run 方法不包含一个监听循环，使用一个无限循环来保持程序运行
    while (true)
    {
        // 你可以在这里添加一些周期性执行的代码，如果需要的话

        // 使循环暂停一段时间，以避免过多占用CPU资源
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
