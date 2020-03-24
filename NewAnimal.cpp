/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the NewAnimal class, which is
**               derived and inherits from the Animal class. NewAnimal
**               is an animal selected by the user to put in the zoo.
**               Keeps track of a its age, cost for buying the new,
**               animal, number of babies, payoff, and cost for food.
*********************************************************************/

#include "NewAnimal.hpp"


/*********************************************************************
** Description: Default constructor for the NewAnimal class, which 
**              sets the age of NewAnimal to 0.
*********************************************************************/
NewAnimal::NewAnimal(): Animal()
{
    age = 0;
}


/*********************************************************************
** Description: Void member function pickNewAnimal sets up the name,
**              cost, number of babies, food cost, and payoff 
**              percentage for a new animal to be put in the zoo. 
*********************************************************************/
void NewAnimal::pickNewAnimal()
{
    int costNewAnimal,
        numBabiesNewAnimal,
        newAnimalFoodCost,
        newAnimalPayoff,
        maxPayoff;

    const int MIN_PRICE = 100,
              MAX_PRICE = 10000,
              MIN_BABIES = 1,
              MAX_BABIES = 10,
              MIN_FOOD_COST = 1,
              MAX_FOOD_COST = 100,
              MIN_PAYOFF = 10,
              MAX_PAYOFF = 50,
              MIN_ANIMALS = 1,
              MAX_ANIMALS = 2;

    //Setting new animal's name
    cout << "What new animal species do you want to add to the zoo?" << endl;
    cout << "Enter its name: ";
    newAnimalName = validInput();

    cout << "How much does one " << newAnimalName << " cost?" << endl;
    cout << "Enter a number from " << MIN_PRICE << " to " << MAX_PRICE << ": ";
    costNewAnimal = validInput(MIN_PRICE, MAX_PRICE);

    //Cost for buying one new animal
    setCost(costNewAnimal);

    cout << "How many babies does one " << newAnimalName << " have?" << endl;
    cout << "Enter a number from " << MIN_BABIES 
         << " to " << MAX_BABIES << ": ";
    numBabiesNewAnimal = validInput(MIN_BABIES, MAX_BABIES);

    //Number of babies a new animal has
    setBabies(numBabiesNewAnimal);

    cout << "What is the food cost for one " << newAnimalName << "?" << endl;
    cout << "Enter a number from " << MIN_FOOD_COST
         << " to " << MAX_FOOD_COST << ": ";
    newAnimalFoodCost = validInput(MIN_FOOD_COST, MAX_FOOD_COST);

    //Food cost for one new animal
    setFoodCost(newAnimalFoodCost);

    cout << "What percentage of $" << costNewAnimal 
         << " does a " << newAnimalName << " make per day? " << endl;
    cout << "Enter an integer from " << MIN_PAYOFF 
         << " to " << MAX_PAYOFF << " for the percentage: ";
    newAnimalPayoff = validInput(MIN_PAYOFF, MAX_PAYOFF);

    //Money earned from one new animal
    setPayoff(newAnimalPayoff);
}


/*********************************************************************
** Description: Void member function setName takes in the new animal's
**              name as a parameter. Uses to set the name of the
**              new animal.
*********************************************************************/
void NewAnimal::setName(string nameIn)
{
    newAnimalName = nameIn;
}


/*********************************************************************
** Description: Void member function setCost takes in the cost of a
**              new animal as a parameter. Uses to set cost.
*********************************************************************/
void NewAnimal::setCost(double costIn)
{
    cost = costIn;
}


/*********************************************************************
** Description: Void member function setBabies takes in the number of
**              babies the new animal has as a parameter. Uses to set
**              numberOfBabies.
*********************************************************************/
void NewAnimal::setBabies(int babiesIn)
{
    numberOfBabies = babiesIn;
}


/*********************************************************************
** Description: Void member function setFoodCost takes in the food
**              cost of a new animal as a parameter. Uses to set
**              newAnimalFoodCost.
*********************************************************************/
void NewAnimal::setFoodCost(double foodCostIn)
{
    newAnimalFoodCost = foodCostIn;
}


/*********************************************************************
** Description: Void member function takes in an integer representing
**              a percentage as a parameter. Uses to calculate the
**              payoff for a new animal by multiplying the percentage
**              by the cost for the new animal.
*********************************************************************/
void NewAnimal::setPayoff(int payoffPercentIn)
{
    payoff = cost * (payoffPercentIn / 100.0);
}


/*********************************************************************
** Description: Member function getName returns the new animal's name.
*********************************************************************/
string NewAnimal::getName()
{
    return newAnimalName;
}


/*********************************************************************
** Description: Member function calculateFeedingCost takes in an
**              integer representing food quality as a parameter. 
**              Calculates the cost of food depending on the food 
**              quality. Returns the feeding cost for one new animal.
*********************************************************************/
double NewAnimal::calculateFeedingCost(int foodQuality)
{
    double feedingCost;

    //Cheap food is half the price of regular food
    if (foodQuality == CHEAP)
    {
        feedingCost = .5 * newAnimalFoodCost;
    }

    //Generic food is the regular price
    else if (foodQuality == GENERIC)
    {
        feedingCost = newAnimalFoodCost;
    }

    //Premium food is twice the price of regular food
    else if (foodQuality == PREMIUM)
    {
        feedingCost = 2 * newAnimalFoodCost;
    }

    return feedingCost;
}