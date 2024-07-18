package th.ac.ku.kps.oop;

import java.util.Scanner;

public class Shop {
	
	static void addProducts(Product p) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Product code " +p.getCode());
		System.out.print("name: ");
		p.setName(sc.nextLine());
		System.out.print("price: ");
		p.setPrice(sc.nextDouble());
		// doesn't need to close scanner because GC will clear it
	}
	
	static Product findProductCode(Product[] products, String code) {
		for(Product i : products) {
			if(code.equals(i.getCode())) {
				return i;
			}
		}
		return null; // when no code found
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Product p0 = new Product("0", "Mama", 5.5);
		Product p1 = new Product("10", "Lays", 10.5);
		Product p2 = new Product("20");
		Product p3 = new Product("30");
		Product p4 = new Product("40");
		
		Product[] products = {p0,p1,p2,p3,p4};
		
		System.out.println("====== Enter Products detail ========");
		
		addProducts(p2);
		addProducts(p3);
		addProducts(p4);
		
		System.out.println("========= List of Products =========");
		for(Product i : products) {
			i.showProduct();
		}
		
		System.out.println("===== What do you want to buy? =====");
		System.out.println("Enter product code (press -1 to exit)");
		
		String code="0";
		double sum = 0;
		double amount;
		Product P;
		while(!code.equals("-1")) {
			System.out.print("Product code: ");
			code = sc.nextLine();
			
			if(code.equals("-1")){
				break;
			}
			
			P = findProductCode(products, code);
			
			System.out.print("Amount of " + P.getName() + ": ");
			
			amount = sc.nextDouble();
			sc.nextLine();
			sum += (P.getPrice() * amount);
		}
		
		System.out.println("You have to pay " + sum + " Bath");
		sc.close();
		
	}
}
