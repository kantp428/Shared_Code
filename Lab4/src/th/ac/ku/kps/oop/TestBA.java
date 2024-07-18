package th.ac.ku.kps.oop;

public class TestBA {
	public static void main(String[] args) {
		BankAccount bank1 = new BankAccount("Win");
//		Date date1 = new Date(1,11,2015);
		BankAccount bank2 = new BankAccount("Tor",500,new Date(1,11,2015));
		
		System.out.println(bank1.getInfo());
		bank1.property();
		
		System.out.println(bank2.getInfo());
		bank2.property();
		
		bank1.deposit(1000);
		bank2.transfer(bank1, 300);
		
		System.out.println(bank1.getInfo());
		bank1.property();
		
		System.out.println(bank2.getInfo());
		bank2.property();
	}
}
