package th.ac.ku.kps.oop;

public class Date {
	private int date;
	private int month;
	private int year;
	
	public Date(int d, int m, int y) {
		date = d;
		month = m;
		year = y;
	}
	
	public void setAll(int d, int m, int y) {
		date = d;
		month = m;
		year = y;
	}
	
	public void setDate(int n) {
		if(n>0 && n<32) {
			date = n;
		}
	}
	
	public void setMonth(int n) {
		if(n>0 && n<12) {
			month = n;
		}
	}
	
	public void setYear(int n) {
		if(n<=2024) {
			n += 543;
		}
		year = n;
	}
	
	public int getDate() {
		return date;
	}
	
	public int getMonth() {
		return month;	
	}
	
	public int getYear() {
		return year;
	}
}
