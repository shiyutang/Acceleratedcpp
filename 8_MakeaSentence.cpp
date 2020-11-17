//
// Created by Daisy on 2020/11/17.
//

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "7_Use library/using library.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;
    int line_num = 0;

    while (getline(in,line) && line_num<15)
    {
        line_num += 1;
        vector<string> entry = split(line);

        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
    }
    return ret;
}



bool bracketed(const string& s)
{
    return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
}

// 将RAND_MAX 分成 n 个区间，随机抽取整数，看随机数处于哪个位置，从而得到小于n的结果
int nrand(int n)
{
    if (n <= 0|| n> RAND_MAX)
        throw domain_error("Argument ti nrand is out of range");

    const int bucket_size = RAND_MAX/n;
    int r;
    do r = rand()/bucket_size;
    while (r>=n);
    return r;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        auto it = g.find(word);  //找到 sentence 开头的规则
        if (it == g.end())
            throw logic_error("empty rule");

        const Rule_collection c = it->second; // 重定向所有规则

        const Rule r = c[nrand(c.size())];  //随机采用一个规则

        for (auto i = r.begin(); i!= r.end();++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sen(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

int main()
{
    vector<string> sentence = gen_sen(read_grammar(cin));
    auto it = sentence.begin();
    if (!sentence.empty())
    {
        cout << *it;
        ++it;
    }
    while (it != sentence.end())
    {
        cout<< " " << *it ;
        ++it;
    }
    cout << endl;
    return 0;
}




//<none> cat
//<none> dog
//<none> table
//<np> <none>
//<np> <adj><np>
//<adj> large
//<adj> brown
//<adj> absurd
//<verb> jumps
//<verb> sits
//<pos> on the stairs
//<pos> under the sky
//<pos> where it wants
//<sentence> the <np><verb><pos>
// end-of-file