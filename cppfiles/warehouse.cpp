#include "../headers/warehouse.h"


struct products {
    Product_type productName;
    int pieceOfProduct;
};


products wheat{WHEAT ,0};
products corn{CORN,0};
products tomato{TOMATO, 0};




int warehouse::getCapacity() const{
    return capacity;
}
void warehouse::setCapacity(int newCapacity) {
    this->capacity = newCapacity;
}

bool warehouse::getLimit(product *product) {

    if(product->getProductType() == wheat.productName && wheat.pieceOfProduct + product->getYield()> capacity){
        limit = false;
    }
    else if(product->getProductType() == corn.productName && corn.pieceOfProduct + product->getYield() > capacity){
        limit = false;
    }
    else if(product->getProductType() == tomato.productName && tomato.pieceOfProduct + product->getYield()> capacity){
        limit = false;
    }
    else limit = true;

    return limit;

}


void warehouse::setPiece(Product_type productType, int piece) {
    if(productType == wheat.productName){
        wheat.pieceOfProduct += piece;
    }
    else if(productType== corn.productName){
        corn.pieceOfProduct += piece;
    }
    else if(productType== tomato.productName){
        tomato.pieceOfProduct += piece;
    }
}

int warehouse::getPiece(Product_type _productName) {
    if(_productName == wheat.productName){
        return wheat.pieceOfProduct;
    }
    else if(_productName== corn.productName){
        return corn.pieceOfProduct;
    }
    else if(_productName== tomato.productName){
        return tomato.pieceOfProduct;
    }
    return 0;
}

warehouse::warehouse() {
    wheat.pieceOfProduct=0;
    tomato.pieceOfProduct=0;
    corn.pieceOfProduct=0;
}

void warehouse::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("warehouse");
    root.append_child("wheatpiece").text().set(wheat.pieceOfProduct);
    root.append_child("tomatopiece").text().set(tomato.pieceOfProduct);
    root.append_child("cornpiece").text().set(corn.pieceOfProduct);
    root.append_child("capacity").text().set(capacity);
}

void warehouse::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("farm").child("warehouse");
    wheat.pieceOfProduct=root.child("wheatpiece").text().as_int();
    tomato.pieceOfProduct=root.child("tomatopiece").text().as_int();
    corn.pieceOfProduct=root.child("cornpiece").text().as_int();
    capacity=root.child("capacity").text().as_int();

}
