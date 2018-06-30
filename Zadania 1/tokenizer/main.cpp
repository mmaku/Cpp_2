#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <cassert>
#include <set>

template <class InputOperator, class OutputOperator>
auto Tokenizer(InputOperator a, InputOperator b, OutputOperator c) -> void
{
    std::string wyraz;
    while (a!=b)
    {
        if (isalnum(*a))  // The result is true if either isalpha or isdigit would also return true.
        {
            wyraz.push_back(*a);
            a++;
        }

        else
        {
            if(!wyraz.empty())
            {
                *c++=wyraz;
                //*c=wyraz;
            }

            wyraz.clear();
            a++;
        }
    }
}



auto test_Tokenizer() -> void;

auto main() -> int
{
    test_Tokenizer();
    return 0;
}

auto test_Tokenizer() -> void
{
    std::string tekst=
    R"#(People are frustrated by PC kinks and the erratic behavior they
    produce. Such unexpected variations in performance have long
    been smoothed out in refrigerators, televisions, mobile phones,
    and automobiles. As for PCs, telling users that their own
    surfing or program installation choices are to blame
    understandably makes them no less frustrated, even if they
    realize that a more reliable system would inevitably be less
    functional—a trade-off seemingly not required by refrigerator
    improvements. Worse, the increasing reliance on the PC and
    Internet that suggests momentum in their use means that more
    is at risk when something goes wrong. Skype users who have
    abandoned their old-fashioned telephone lines may regret their
    decision if an emergency arises and they need to dial an
    emergency number like 911, only to find that they cannot get
    through, let alone be located automatically. When one’s
    finances, contacts, and appointments are managed using a PC,
    it is no longer merely frustrating if the computer comes down
    with a virus. It is enough to search for alternative architectures.)#";

    // Zittrain, The Future of the Internet, http://yupnet.org/zittrain/archives/14

    std::list<std::string> words;

    Tokenizer(std::begin(tekst),std::end(tekst),std::back_inserter(words));

    std::list<std::string> wdone{"People","are","frustrated","by","PC","kinks",
    "and","the","erratic","behavior","they","produce","Such","unexpected",
    "variations","in","performance","have","long","been","smoothed","out",
    "in","refrigerators","televisions","mobile","phones","and","automobiles",
    "As","for","PCs","telling","users","that","their","own","surfing","or",
    "program","installation","choices","are","to","blame","understandably",
    "makes","them","no","less","frustrated","even","if","they","realize",
    "that","a","more","reliable","system","would","inevitably","be","less",
    "functional","a","trade","off","seemingly","not","required","by",
    "refrigerator","improvements","Worse","the","increasing","reliance","on",
    "the","PC","and","Internet","that","suggests","momentum","in","their",
    "use","means","that","more","is","at","risk","when","something","goes",
    "wrong","Skype","users","who","have","abandoned","their","old",
    "fashioned","telephone","lines","may","regret","their","decision","if",
    "an","emergency","arises","and","they","need","to","dial","an",
    "emergency","number","like","911","only","to","find","that","they",
    "cannot","get","through","let","alone","be","located","automatically",
    "When","one","s","finances","contacts","and","appointments","are",
    "managed","using","a","PC","it","is","no","longer","merely",
    "frustrating","if","the","computer","comes","down","with","a","virus",
    "It","is","enough","to","search","for","alternative","architectures"};
    assert(words==wdone);

    std::vector<char> tekst_jako_vector(std::begin(tekst),std::end(tekst));

    std::set<std::string> words_list;
    Tokenizer(std::begin(tekst_jako_vector),
              std::end(tekst_jako_vector),
              std::inserter(words_list,std::end(words_list)));

    std::list<std::string> wldone{"911","As","Internet","It","PC","PCs","People","Skype","Such",
    "When","Worse","a","abandoned","alone","alternative","an","and","appointments",
    "architectures","are","arises","at","automatically","automobiles","be","been","behavior",
    "blame","by","cannot","choices","comes","computer","contacts","decision","dial","down",
    "emergency","enough","erratic","even","fashioned","finances","find","for","frustrated",
    "frustrating","functional","get","goes","have","if","improvements","in","increasing",
    "inevitably","installation","is","it","kinks","less","let","like","lines","located","long",
    "longer","makes","managed","may","means","merely","mobile","momentum","more","need","no",
    "not","number","off","old","on","one","only","or","out","own","performance","phones",
    "produce","program","realize","refrigerator","refrigerators","regret","reliable",
    "reliance","required","risk","s","search","seemingly","smoothed","something","suggests",
    "surfing","system","telephone","televisions","telling","that","the","their","them","they",
    "through","to","trade","understandably","unexpected","use","users","using","variations",
    "virus","when","who","with","would","wrong"};

    assert(wldone.size()==words_list.size());
    assert(std::equal(std::begin(words_list),std::end(words_list),std::begin(wldone)));

    std::cerr<<"Testy ok\n";
}
