/*
Name-Nishant vilas Argade
Div-A Roll no- 03
sit no-S190538505 
Batch-S1

 Program Statement:

Design and develop a context for given case study and implement an interface for Vehicles Consider the example of vehicles like bicycle, car and bike. All Vehicles have common functionalities such as Gear Change, Speed up and apply breaks. Make an interface and put all these common functionalities. Bicycle, Bike, Car classes should be implemented for all these functionalities in their own class in their own way.
*/
import java.io.*;
import java.util.*;

interface Engine {
	// All of this Abstract Methods
	void gearChange(int newGear);

	void speedUp(int increment);

	void ApplyBrakes(int decrement);

}

class Bicycle implements Engine {

	int speed;
	int gear;
	int brake;

	@Override
	public void gearChange(int changeGear) {
		gear = changeGear;
	};

	@Override
	public void speedUp(int speedIncrease) {
		speed = speed + speedIncrease;
	};

	@Override
	public void ApplyBrakes(int SpeedDecrement) {
		speed = speed - SpeedDecrement;
	};

	public void currentState() {
		System.out.println("Gear : " + gear + " and " + "Speed : " + speed);
	}

}

class Bike implements Engine {

	int speed;
	int gear;
	int brake;

	@Override
	public void gearChange(int changeGear) {
		gear = changeGear;
	};

	@Override
	public void speedUp(int speedIncrease) {
		speed = speed + speedIncrease;
	};

	@Override
	public void ApplyBrakes(int SpeedDecrement) {
		speed = speed - SpeedDecrement;
	};

	public void currentState() {
		System.out.println("Gear : " + gear + " and " + "Speed : " + speed);
	}

}

class Car implements Engine {

	int speed;
	int gear;
	int brake;

	@Override
	public void gearChange(int changeGear) {
		gear = changeGear;
	};

	@Override
	public void speedUp(int speedIncrease) {
		speed = speed + speedIncrease;
	};

	@Override
	public void ApplyBrakes(int SpeedDecrement) {
		speed = speed - SpeedDecrement;
	};

	public void currentState() {
		System.out.println("Gear : " + gear + " and " + "Speed : " + speed);
	}

}

class InterfaceForVehicals {
	public static void main(String[] args) {
		
		// creating instance of Bicycle,bike and car classes and calling their method;

		Bicycle bicycle1 = new Bicycle();
		bicycle1.gearChange(3);
		bicycle1.speedUp(25);
		bicycle1.ApplyBrakes(10);
		System.out.println("bicycle current state :");
		bicycle1.currentState();

		Bike bike1 = new Bike();
		bike1.gearChange(4);
		bike1.speedUp(65);
		bike1.ApplyBrakes(20);
		System.out.println("Bike current state :");
		bike1.currentState();

		Car car1 = new Car();
		car1.gearChange(4);
		car1.speedUp(80);
		car1.ApplyBrakes(30);
		System.out.println("Car current state :");
		car1.currentState();

	}
}


