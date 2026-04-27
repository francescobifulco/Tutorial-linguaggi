public class Product<T, U> {
    T item;
    U price;

    Product(T item, U prince){
        this.item = item;
        this.price = prince;
    }

    public T getItem(){
        return this.item;
    }

    public U getPrice(){
        return this.price;
    }
}
