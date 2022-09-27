
#include <iostream>
#include <cstring>
using namespace std;

class Product {
	int id;
	char name[100];
	int mrp;
	int selling_price;

public:
    // constructor
    Product() {
        cout << "Inside constructor" << endl;
    }

    //Parameterized constructor
    Product(int id, char name[], int mrp, int selling_price) {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        strcpy(this->name, name);
    }

    // Copy constructor
/*    Product(Product &x) {
        id = x.id;
        //name = x.name;
        mrp = x.mrp;
        selling_price = x.selling_price;
    }
*/
    void setMrp(int price) {
        mrp = price;
    }

    void setSellingPrice(int price) {
        if (price > mrp)
            selling_price = mrp;
        else
            selling_price = price;
    }

    int getMrp() { return mrp; }
    int getSellingPrice() { return selling_price; }
    void showDetails() {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "MRP : " << mrp << endl;
        cout << "Selling Price : " << selling_price << endl;

        cout << "======================" << endl;
    }
};

int main() {
	//Product camera;
    char product_name[] = {'S', 'o', 'n', 'y', '\0'};
	Product camera(101, product_name, 28000, 26000);

    // copied using a special constructor -> Copy constructor
    Product webcam(camera);

    Product handyCam = camera; // this also makes a call to the copy constructor

    camera.showDetails();
    webcam.showDetails();
    handyCam.showDetails();

  //  camera.setMrp(100);
  //  camera.setSellingPrice(190);
	//camera.mrp = 100;
	//camera.selling_price = 200;
	
	//cout << sizeof(camera) << endl;
	//cout << "MRP = " << camera.getMrp() << endl;
	//cout << "Selling Price = " << camera.getSellingPrice() << endl;
}
