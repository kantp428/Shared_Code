package th.ac.ku.kps.oop;

public class BankAccount {
	private String name;
	private double amount;
	private Date date;
	public BankAccount(String n) {
		name = n;
		amount = 0;
		Date date1 = new Date (13, 7, 2567);
		this.date = date1;
	}
	
	public BankAccount(String n, double a, Date d) {
		name = n;
		amount = a;
		date = d;
	}
	
	public void deposit(double add) {
		amount += add;
	}
	
	public boolean withdraw(double minus) {
		boolean status = false;
		if(amount - minus >= 0) {
			amount -= minus;
			status = true;
		}
		return status;
	}
	
	public void transfer(BankAccount other, double minus) {
		if(amount - minus >= 0) {
			amount -= minus;
			other.deposit(minus);
		}
	}
	
	public void property() {
		System.out.println("Amount: " + amount);
	}
	
	public String getInfo() {
		String out = name +" "+ date.getDate() + "/" + date.getMonth() + "/" + date.getYear();
		return out;
	}
	
//	public void showDate() {
//		System.out.println(date.getDate() + "/" + date.getMonth() + "/" + date.getYear());
//	}
}
