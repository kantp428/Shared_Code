package th.ac.ku.kps.oop;

public class Product {
	private String Name;
	private String Code;
	private double Price;
	
	public Product(String c, String n, double p) {
		Code = c;
		Name = n;
		Price = p;
	}
	
	public Product(String c) {
		Code = c;
	}
	//Setter
	public void setCode(String code) {
		Code = code;
	}
	
	public void setName(String name) {
		Name = name;
	}
	
	public void setPrice(double price) {
		Price = price;
	}
	//Getter
	public String getCode() {
		return Code;
	}
	
	public String getName() {
		return Name;
	}
	
	public double getPrice() {
		return Price;
	}
	//method
	public void showProduct() {
		System.out.println("Product code " + Code);
		System.out.println("Name:" + Name + " , Price: " + Price);
	}
}
