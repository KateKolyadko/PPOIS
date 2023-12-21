#include "pch.h"
#include "CppUnitTest.h"
#include "D:\лабы\ппоис\museum\museum\Museum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MuseumTest
{
	TEST_CLASS(MuseumTest)
	{
	public:
		TEST_METHOD(CuratorNumber)
		{
			Museum mus("name");
			mus.addCurator("Anthony", "312");
			std::string expected = "312";
			Assert::AreEqual(expected, mus.getCuratorNumber("Anthony"));
		}
		TEST_METHOD(RemoveCurator)
		{
			Museum mus("name");
			mus.addCurator("Anthony", "312");
			mus.removeCurator("Anthony");
			std::string expected = "None";
			Assert::AreEqual(expected, mus.getCuratorNumber("Anthony"));
		}
		TEST_METHOD(ArtifactName)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			std::string expected = "Knife";
			Assert::AreEqual(expected,mus.getExhibitionArtifacts("Ancient")[0].getArtifactName());
		}

		TEST_METHOD(VisitorNumber)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.addVisitor("Kate", "33", 20);
			mus.buyVisitorTicket("Kate", "Ancient", 10);
			std::string expected = "33";
			Assert::AreEqual(expected, mus.getVisitorNumber("Kate"));
		}

		TEST_METHOD(VisitorMoney)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.addVisitor("Kate", "33", 20);
			mus.buyVisitorTicket("Kate", "Ancient", 10);
			mus.addVisitorMoney("Kate", 30);
			int expected = 40;
			Assert::AreEqual(expected, mus.getVisotorMoney("Kate"));
		}

		TEST_METHOD(Resrvation)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.addVisitor("Kate", "33", 20);
			mus.addVisitorMoney("Kate", 30);
			mus.buyVisitorTicket("Kate", "Ancient", 10);
			mus.addReservation("Ancient");
			int expected = 1;
			Assert::AreEqual(expected, mus.getReservationVisitorsCount("Ancient"));
		}

		TEST_METHOD(ExhibitTheme)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			
			std::string expected = "Old";
			Assert::AreEqual(expected, mus.getExhibitTheme("Ancient"));
		}
		TEST_METHOD(RemoveArtifact)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.removeExhibitArtifact("Ancient", "Knife");
			auto& artifacts = mus.getExhibitionArtifacts("Ancient");

			size_t expected = 0;
			Assert::AreEqual(expected, artifacts.size());
		}
		TEST_METHOD(ExhibitStatus)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.removeExhibitArtifact("Ancient", "Knife");
			mus.switchStatus("Ancient");
			mus.openExhibition("Ancient");
			mus.closeExhibition("Ancient");
			mus.switchStatus("Ancient");

			bool expected = false;
			Assert::AreEqual(expected, mus.getStatus("Ancient"));
		}

		TEST_METHOD(Feedback)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.addVisitor("Kate", "33", 20);
			mus.makeVisitorFeedback("Kate", "Ancient", 10);

			float expected = 10.f;
			Assert::AreEqual(expected, mus.getAverageExhitionRating("Ancient"));
		}

		TEST_METHOD(FeedbackAverage)
		{
			Museum mus("name");
			mus.addExhibit("Ancient", "Old");
			mus.addExhibitArtifact("Ancient", "Knife");
			mus.addVisitor("Kate", "33", 20);
			mus.makeVisitorFeedback("Kate", "Ancient", 10);

			float expected = 10.f;
			Assert::AreEqual(expected, mus.getAverageRating());
		}
	};
}
