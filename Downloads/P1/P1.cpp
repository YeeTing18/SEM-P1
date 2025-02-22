#include <iostream>
#include <string>
#include <vector>

class DetectLengthiestRepeatingCharacters {
public:
    static std::string lRepeatingChars(const std::string& strInput) {
        int length = strInput.length();
        std::vector<std::vector<int>> arr(length + 1, std::vector<int>(length + 1, 0));
        int max = 0, last = 0;
   
        for (int x = 1; x <= length; x++) {
            for (int n = x + 1; n <= length; n++) {
                if (strInput[x - 1] == strInput[n - 1] && arr[x - 1][n - 1] < (n - x)) {
                    arr[x][n] = arr[x - 1][n - 1] + 1;
                    if (arr[x][n] >= max) {
                        max = arr[x][n];
                        last = x;
                    }
                } else {
                    arr[x][n] = 0;
                }
            }
        }
   
        return strInput.substr(last - max, max);
    }
};

int main() {
    std::string input = "123012321230231232133211223123";
    input = "abcab";
    std::cout << "Lengthiest repeating characters: " << DetectLengthiestRepeatingCharacters::lRepeatingChars(input) << std::endl;
    return 0;
}
   
