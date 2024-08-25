/*
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。
*/
#include <vector>
#include <string>
#include <cstring>
class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> ret;

        int index = -1;
        int words_length = 0;
        int words_length_with_blank = 0;
        int words_count = 0;

        for (int i = 0; i < words.size(); i++) {
            if (index == -1) {
                index = i;
            }
            if (words_length_with_blank != 0) {
                words_length_with_blank += words[i].length() + 1;
            } else {
                words_length_with_blank += words[i].length();
            }

            if (words_length_with_blank >= maxWidth) {
                if (words_length_with_blank == maxWidth) {
                    words_count++;
                    words_length += words[i].length();

                } else {
                    i--;
                }
               
                if (words_count == 0) {
                    return ret;
                }
                ret.emplace_back(fullOneLine(words, index, words_length, words_count, maxWidth));

                words_length = 0;
                words_length_with_blank = 0;
                words_count = 0;
                index = -1;
                continue;
            }
            words_count++;
            words_length += words[i].length();
        }

        if (words_count > 0) {
            ret.emplace_back(fullLastLine(words, index, words_length, words_count, maxWidth));
        }

        return ret;
    }


    std::string fullOneLine(std::vector<std::string>& words, int index, int words_length, int words_count, int maxWidth) {
        int blank_length = maxWidth - words_length;
        int every_blank_length = blank_length;
        int extra_blank_length = 0;
        if (words_count > 1) {
            every_blank_length = blank_length / (words_count - 1);
            extra_blank_length = blank_length % (words_count - 1);
        }

        std::string ret;
        ret.reserve(maxWidth);
        if (words_count > 1) {
            for (int i = index; i < index + words_count; i++) {
                if (i != index) {
                    if (extra_blank_length > 0) {
                        ret.append(makeBlank(every_blank_length + 1));
                        extra_blank_length--;
                    } else {
                        ret.append(makeBlank(every_blank_length));
                    }
                }
                ret.append(words[i]);
            }

        } else {
            ret.append(words[index]);
            ret.append(makeBlank(blank_length));
        }
        return ret;
    }

    std::string fullLastLine(std::vector<std::string>& words, int index, int words_length, int words_count, int maxWidth) {
        int blank_length = maxWidth - words_length;

        std::string ret;
        ret.reserve(maxWidth);
        for (int i = index; i < index + words_count; i++) {
            if (i != index) {
                ret.append(makeBlank(1));
                blank_length -= 1;
            }
            ret.append(words[i]);
        }
        ret.append(makeBlank(blank_length));
        return ret;
    }

    std::string makeBlank(int length) {
        return std::string(length, ' ');
    }
};
 