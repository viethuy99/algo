
// Verified: https://acm.timus.ru/problem.aspx?space=1&num=1414

#include <cassert>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie_type;

void print_prefix_match(const trie_type &t, const string &key)
{

    auto match_range = t.prefix_range(key);
    cout << distance(match_range.first, match_range.second) << endl;
    for (auto it = match_range.first; it != match_range.second; ++it)
        cout << *it << ' ';
    cout << endl;
}

int main()
{
    trie_type t;

    // Insert some entries.
    assert(t.insert("I").second == true);
    assert(t.insert("wish").second == true);
    assert(t.insert("that").second == true);
    assert(t.insert("I").second == false);
    assert(t.insert("could").second == true);
    assert(t.insert("ever").second == true);
    assert(t.insert("see").second == true);
    assert(t.insert("a").second == true);
    assert(t.insert("poem").second == true);
    assert(t.insert("lovely").second == true);
    assert(t.insert("as").second == true);
    assert(t.insert("a").second == false);
    assert(t.insert("trie").second == true);

    // Now search for prefixes.
    print_prefix_match(t, "");
    print_prefix_match(t, "a");
    print_prefix_match(t, "as");
    print_prefix_match(t, "ad");
    print_prefix_match(t, "t");
    print_prefix_match(t, "tr");
    print_prefix_match(t, "trie");
    print_prefix_match(t, "zzz");

    /**
     *  All keys whose prefix matches "":
        I a as could ever lovely poem see that trie wish 
        All keys whose prefix matches "a":
        a as 
        All keys whose prefix matches "as":
        as 
        All keys whose prefix matches "ad":

        All keys whose prefix matches "t":
        that trie 
        All keys whose prefix matches "tr":
        trie 
        All keys whose prefix matches "trie":
        trie 
        All keys whose prefix matches "zzz":
     * 
    */

    return 0;
}
