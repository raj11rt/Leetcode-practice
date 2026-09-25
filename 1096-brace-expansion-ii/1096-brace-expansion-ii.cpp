class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res;
        vector<set<string>> parts;

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                i++;
                continue;
            }

            set<string> cur;

            if (s[i] == '{') {
                i++;
                cur = parse(s, i);
                i++; // skip '}'
            } 
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            parts.push_back(cur);
        }

        // Concatenate all consecutive parts
        res.insert("");

        for (auto &part : parts) {
            set<string> temp;

            for (auto &a : res)
                for (auto &b : part)
                    temp.insert(a + b);

            res = temp;
        }

        // The above treats commas incorrectly, so handle
        // the expression by splitting at comma levels.
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }

    set<string> solve(string &s, int &i) {
        set<string> result, current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto &x : current)
                    result.insert(x);

                current.clear();
                current.insert("");
                i++;
            }
            else {
                set<string> part;

                if (s[i] == '{') {
                    i++;
                    part = solve(s, i);
                    i++;
                }
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;

                for (auto &a : current)
                    for (auto &b : part)
                        temp.insert(a + b);

                current = temp;
            }
        }

        for (auto &x : current)
            result.insert(x);

        return result;
    }
};