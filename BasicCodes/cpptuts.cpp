
#include <iostream>
class Car {
  protected:
         int color;
         int currentSpeed;
         int maxSpeed=100;
  public:
         void applyHandBrake(){
             this->currentSpeed = 0;
         }
         void pressHorn(){
             std::cout << "Teeeeeeeeeeeeent" << std::endl; // funny noise for a horn
         }
         void driveAtFullSpeed(int mph){
              // code for moving the car ahead;
         	this->currentSpeed=mph;
         	std::cout << this->currentSpeed <<std::endl;
         	if(mph > 200)
         		std::cout << "BUSTED!"<<std::endl; 
         }
         void stats()
         {
         	std::cout << "Speed: "<< this->currentSpeed<< std::endl;
         }
};

class PlayerCar : public Car {

};

class PoliceCar : public Car {
  private:
         bool sirenOn;  // identifies whether the siren is on or not
         bool inAction; // identifies whether the police is in action (following the player) or not
  public:
         bool isInAction(){
             return this->inAction;
         }
         bool nitro();

};
bool PoliceCar::nitro()
{
	driveAtFullSpeed(300);
}
int main()
{
	PoliceCar pc;
	pc.stats();
	pc.nitro();
	pc.stats();

}