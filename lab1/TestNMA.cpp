#include "pch.h"
#include "CppUnitTest.h"
#include "../project1/NMA.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestNMA
{
    TEST_CLASS(TestNMA)
    {
    public:

        TEST_METHOD(AddRule_Fragment_Alphabet_False)
        {
            NMA nma;
            string alphabet = "abcdefghijklmnop";
            nma.createAlphabet(alphabet);
            string fragment = "qrs";
            string replacement = "def";
            string expectedOutput = "does not correspond to the alphabet\n";
            stringstream buf;
            streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

            nma.addRule(fragment, replacement);
            cout.rdbuf(oldbuf);

            string actualOutput = buf.str();
            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(AddRule_Replacement_Alphabet_False)
        {
            NMA nma;
            string alphabet = "abcdefghijklmnop";
            nma.createAlphabet(alphabet);
            string fragment = "fghi";
            string replacement = "qwtads";
            string expectedOutput = "does not correspond to the alphabet\n";
            stringstream buf;
            streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

            nma.addRule(fragment, replacement);
            cout.rdbuf(oldbuf);

            string actualOutput = buf.str();
            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(AddRule_Empty_Replacement_Alphabet_True)
        {
            NMA nma;
            string alphabet = "abcdefghijklmnop";
            nma.createAlphabet(alphabet);
            string fragment = "abc";
            string replacement = "^";

            nma.addRule(fragment, replacement);

            Assert::AreEqual(replacement, nma.getReplacement(1));
            Assert::AreEqual(fragment, nma.getFragment(1));
        }

        TEST_METHOD(Algorithm_Test1) {
            NMA nma;
            string alphabet = "ad";
            nma.createAlphabet(alphabet);
            string word = "dddaaadadaad";
            nma.createStr(word);
            nma.addRule("da", "ad");
            nma.algorithm();
            string result = nma.resultStr();
            string expectedresult = "aaaaaadddddd";

            Assert::AreEqual(expectedresult, result);
        }

        TEST_METHOD(Algorithm_Test2) {
            NMA nma;
            string alphabet = "ad";
            nma.createAlphabet(alphabet);
            string word = "da";
            nma.createStr(word);
            nma.addRule("a", "d");
            nma.addRule("d", "a");
            string expectedOutput = "the cycle is considered endless\n";

            stringstream buf;
            streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
            nma.algorithm();

            cout.rdbuf(oldbuf);
            string actualOutput = buf.str();

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(Algorithm_Test3) {
            NMA nma;
            string alphabet = "qwertyuiopasdfghjklzxcvbnm";
            nma.createAlphabet(alphabet);
            string word = "asdfghj";
            nma.createStr(word);
            nma.addRule("asd", "^");
            nma.addRule("hj", "t");
            nma.addRule("fg", "hj");

            nma.algorithm();
            string result = nma.resultStr();
            string expectedresult = "tt";
            Assert::AreEqual(expectedresult, result);

        }

    };

}
