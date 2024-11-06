#include <iostream>
#include <cmath>


int main (){
    // input grades
    double final {-2};
    double finalmax {-2};

    double midterm {-2};
    double midtermax {-2};

    double project1 {-2};
    double project1max {-2};

    double project2 {-2};
    double project2max {-2};

    double project3 {-2};
    double project3max {-2};

    double project4 {-2};
    double project4max {-2};

    double project5 {-2};
    double project5max {-2};

    double examTotal , projectTotal;

    // calculation variables
    float finalPerc {};
    float midPerc {};
    float proj1Perc {};
    float proj2Perc {};
    float proj3Perc {};
    float proj4Perc {};
    float proj5Perc {};


    // input final
    while ((finalmax <=0)|| (finalmax != std::round( finalmax))) {
            std::cout << "Enter Maxmimum mark for final: ";
            std::cin>> finalmax;
    }
    while (final < 0 || final > finalmax ) {
            std::cout << "Enter Achieved mark for final: ";
            std::cin>> final;

    }


    finalPerc = 100*(final/finalmax); 

    //input midterm
   while ((midtermax <=0)|| (midtermax != std::round( midtermax))) {
            std::cout << "Enter Maxmimum mark for midterm: ";
            std::cin>> midtermax;
    }
    while (midterm < 0 || midterm > midtermax ) {
            std::cout << "Enter Achieved mark for midterm: ";
            std::cin>> midterm;

    }
    
    midPerc = 100*(midterm/midtermax);

   while ((project1max <=0)|| (project1max != std::round(project1max))) {
            std::cout << "Enter Maxmimum mark for Project 1: ";
            std::cin>> project1max;
    }
    while (project1 < 0 || project1 > project1max ) {
            std::cout << "Enter Achieved mark for Project 1: ";
            std::cin>> project1;

    }
    
    proj1Perc = 100*(project1/project1max);
   while ((project2max <=0)|| (project2max != std::round(project2max))) {
            std::cout << "Enter Maxmimum mark for Project 2: ";
            std::cin>> project2max;
    }
    while (project2 < 0 || project2 > project2max ) {
            std::cout << "Enter Achieved mark for Project 2: ";
            std::cin>> project2;

    }
        proj2Perc = 100*(project2/project2max);
   while ((project3max <=0)|| (project3max != std::round(project3max))) {
            std::cout << "Enter Maxmimum mark for Project 3: ";
            std::cin>> project3max;
    }
    while (project3 < 0 || project3 > project3max ) {
            std::cout << "Enter Achieved mark for Project 3: ";
            std::cin>> project3;

    }
        proj3Perc = 100*(project3/project3max);
   while ((project4max <=0)|| (project4max != std::round(project4max))) {
            std::cout << "Enter Maxmimum mark for Project 4: " ;
            std::cin>> project4max;
    }
    while (project4< 0 || project4 > project4max ) {
            std::cout << "Enter Achieved mark for project 4: ";
            std::cin>> project4;
            }
        proj4Perc = 100*(project4/project4max);
   while ((project5max <=0)|| (project5max != std::round(project5max))){
            std::cout << "Enter Maxmimum mark for Project 5: ";
            std::cin>> project5max;
    }
    while (project5< 0 || project5 > project5max ) {
            std::cout << "Enter Achieved mark for project 5: ";
            std::cin>> project5;

    }
        proj5Perc = 100*(project5/project5max);



     //final exam supremacy
     if (midPerc < finalPerc){

        midPerc = finalPerc; 
     }
     if (proj1Perc < finalPerc) {
        proj1Perc = finalPerc;
     } 
    if (proj2Perc < finalPerc) {
        proj2Perc = finalPerc;
    }
    if (proj3Perc < finalPerc) {
        proj3Perc = finalPerc;
    }
    if (proj4Perc < finalPerc) {
        proj4Perc = finalPerc;
    }
    if (proj5Perc < finalPerc) {
        proj5Perc = finalPerc;
    }
  

    examTotal = 0.75 * finalPerc + 0.25 * midPerc;
    projectTotal = 0.2 * (proj1Perc + proj2Perc + proj3Perc + proj4Perc + proj5Perc);

    // Final grade calculation
    double final_grade;
    double factor;

    if (examTotal <= 40) {
        final_grade = examTotal;
    } else if (examTotal >= 60) {
        final_grade = 0.5 * finalPerc + (1.0 / 6.0) * midPerc + (1.0 / 3.0) * projectTotal;
    } else {
        factor = (examTotal - 40) / 20.0;
        final_grade = projectTotal * (1.0 / 3.0) * factor + examTotal * (1 - (1.0 / 3.0) * factor);
    }

    final_grade = std::round(final_grade + 1e-12);
    std::cout << static_cast<int>(final_grade) << std::endl;

    return 0;
} 