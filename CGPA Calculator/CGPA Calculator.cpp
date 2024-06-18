#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

static double sumOfVector(std::vector<double> vector)
{
	double sum;
	sum = std::accumulate(vector.begin(), vector.end(), 0);
	return sum;
}

static double CGPAScore(std::vector<double> vector)
{
	double score;
	score = sumOfVector(vector) / vector.size();
	return score;
}

int main()
{
	std::cout << "Welcome to the CGPA Calculator!\nPlease below enter the values of the scores you want to use\nAnd then type 'done' after you'v written all the scores:\n\n(use '.' for any broken values)\n\n";
	
	std::string input;
	std::vector<double> gradeScoreList;
	while (input != "done")
	{
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), tolower);

		double vectorGradeValue;
		bool addToGradeScoreList = true;
		try
		{
			if (input != "done") { vectorGradeValue = std::stod(input); }
			else { break; }
		}

		catch (const std::exception&)
		{
			std::cout << "That's not a valid input, use only numbers and type 'done' when you finish!\n";
			addToGradeScoreList = false;
		}

		if (addToGradeScoreList == true)
		{
			gradeScoreList.insert(gradeScoreList.end(), vectorGradeValue);
		}
		addToGradeScoreList = true;
	}
	std::cout << "Your CGPA score is: " << CGPAScore(gradeScoreList) << "!\n";
	system("pause");
}