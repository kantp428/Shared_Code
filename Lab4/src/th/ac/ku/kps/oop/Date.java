package th.ac.ku.kps.oop;

public class Date {
	private int date = 20;
	private int month = 7;
	private int year = 2567;
	
	public Date(int d, int m, int y) {
		if(d>0 && d<32 && m>0 && m<13) {
			date = d;
			month = m;
			if(y<=2024) {
				year = y + 543;
			}
		}
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
