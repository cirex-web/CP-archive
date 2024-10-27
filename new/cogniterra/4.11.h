
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/

std::tuple<int, std::string, std::string>
LocalAlignment(int match_reward, int mismatch_penalty, int indel_penalty,
               std::string s, std::string t);

std::tuple<int, std::string, std::string>
AffineAlignment(int match_reward, int mismatch_penalty,
                int gap_opening_penalty, int gap_extension_penalty,
                std::string s, std::string t);
#ifndef UCF_4_11_H
#define UCF_4_11_H

#endif //UCF_4_11_H
