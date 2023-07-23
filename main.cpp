#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string searching_challenge(const std::string& str) {
    std::vector<std::string> words;
    std::string word;
    std::string delimiters = " ";
    size_t startPos = 0;
    size_t endPos = str.find_first_of(delimiters, startPos);

    // Split the input string into words
    while (endPos != std::string::npos) {
        word = str.substr(startPos, endPos - startPos);
        words.push_back(word);
        startPos = str.find_first_not_of(delimiters, endPos);
        if (startPos == std::string::npos)
            break;
        endPos = str.find_first_of(delimiters, startPos);
    }
    if (startPos != std::string::npos) {
        word = str.substr(startPos);
        words.push_back(word);
    }

    std::string max_word;
    int max_count = 1; // Minimum count for comparison is 1 (single occurrence)

    for (const auto& w : words) {
        int char_counts[256] = { 0 }; // Assuming ASCII characters
        int repeat_count = 0;

        // Count occurrences of each character in the word
        for (char c : w) {
            char_counts[static_cast<unsigned char>(c)]++;
        }

        // Find the maximum count of any character in the word
        for (int count : char_counts) {
            if (count > 1 && count > max_count) {
                repeat_count = count;
                max_count = count;
            }
        }

        // If the word has the greatest number of repeated letters, store it
        if (repeat_count == max_count) {
            max_word = w;
            break; // Break out of the loop to get the first word with the max count
        }
    }

    if (max_word.empty()) {
        return "-1";
    }

    // Concatenate the first output word with the ChallengeToken
    std::string output1 = max_word + "egfs90hz78b";

    // Replace every third character in the first output with 'X'
    for (size_t i = 2; i < output1.length(); i += 3) {
        output1[i] = 'X';
    }

    // Concatenate the second output word with the ChallengeToken
    std::string output2 = max_word + "egfs90hz78b";

    // Replace every third character in the second output with 'X'
    for (size_t i = 2; i < output2.length(); i += 3) {
        output2[i] = 'X';
    }

    // Return the two concatenated and modified output strings
    return output1 + output2;
}

int main() {
    // Test the function with the example input
    std::string input = "Today, is the greatest day ever!";
    std::string output = searching_challenge(input);
    std::cout << output << std::endl; // Output: "greatestegfXhXstegfs90hz78bgreatestegfXhXstegfs90hz78b"

    return 0;
}
