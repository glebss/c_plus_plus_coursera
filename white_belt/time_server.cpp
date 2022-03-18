#include <string>
#include <stdexcept>
#include <system_error>
using namespace std;

// string AskTimeServer() {
//     return "";
// }


class TimeServer {
public:
  string GetCurrentTime() {
      try {
           last_fetched_time = AskTimeServer();
      } catch (system_error& err) {
        }
    return last_fetched_time;
  }
private:
  string last_fetched_time = "00:00:00";
};