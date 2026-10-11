#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

   // Structure to store course details
   struct Course
{
   string courseName;
   double gradePoint;
   double creditHours;
};
   int main()
{
   int n;
   cout << "--- CGPA CALCULATOR ---" << endl;
   cout << "Enter the number of courses student : ";
   cin >> n;

   vector<Course> courses(n);
   double totalGradePoints = 0.0;
   double totalCredits = 0.0;

   // Input grades and credit hours for each course
   for (int i = 0; i < n; ++i)
{
   cout << "\n--- Course " << i + 1 << " ---" << endl;
   cout << "Enter course name : ";
   cin >> courses[i].courseName;
   cout << "Enter grade points : ";
   cin >> courses[i].gradePoint;
   cout << "Enter credit hours : ";
   cin >> courses[i].creditHours;

   // Calculate total credits and total grade points (grade x credit hours)[cite: 1]
   totalGradePoints += (courses[i].gradePoint * courses[i].creditHours);
   totalCredits += courses[i].creditHours;
}
   // Compute GPA/CGPA[cite: 1]
   double cgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;

   // Display individual course grades and final CGPA[cite: 1]
   cout << "\n===============================================" << endl;
   cout << "               ACADEMIC REPORT                 " << endl;
   cout << "===============================================" << endl;
   cout << left << setw(20) << "Course Name" << setw(15) << "Grade Point" << setw(15) << "Credits" << endl;
   cout << "-----------------------------------------------" << endl;
   for (const auto& c : courses) {
   cout << left << setw(20) << c.courseName << setw(15) << c.gradePoint << setw(15) << c.creditHours << endl;
}
   cout << "-----------------------------------------------" << endl;
   cout << fixed << setprecision(2);
   cout << "Total Credits : " << totalCredits << endl;
   cout << "Total Grade Points : " << totalGradePoints << endl;
   cout << "Final Overall CGPA : " << cgpa << endl;
   cout << "===============================================" << endl;
  
   return 0;
}