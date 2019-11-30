BookAction()
{
	
	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR04_Select_Flight");

	web_reg_save_param("firstName",
                   "LB=name=\"firstName\" value=\"",
                   "RB=\" size=", LAST);
	
	web_reg_save_param("lastName",
                   "LB=name=\"lastName\" value=\"",
                   "RB=\" size=", LAST);
	
	/*
	web_reg_save_param("address1",
                   "LB=name=\"address1\" value=\"",
                   "RB=\" size=", LAST);
	
	web_reg_save_param("address2",
                   "LB=name=\"address2\" value=\"",
                   "RB=\" size=", LAST);                   
   	*/
   	
   	/*
   	Во время записи данного скрипта при оформлении заказа 
	поля "Street Address", "City/State/Zip", "Credit Card" и "Exp Date"
	не были заполнены, поэтому не могут быть считаны и параметризированы
	с помощью функции web_reg_save_param. В реальном приложении пользователь не сможет
	офрмить заказ, пока не заполнит вышеуказанные поля. В данном случае поля
	"Street Address", "City/State/Zip", "Credit Card" и "Exp Date" заполняются,
	поскольку данные значения раннее были сохранены в кэше и подставляются из него.
	*/
   	
	web_reg_save_param("pass1",
                   "LB=name=\"pass1\" value=\"",
                   "RB=\" size=", LAST);
	
	/*
	web_reg_save_param("creditCard",
                   "LB=name=\"creditCard\" value=\"",
                   "RB=\" size=", LAST);
	
	web_reg_save_param("expDate",
                   "LB=name=\"expDate\" value=\"",
                   "RB=\" size=", LAST);
    */
   
	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={flightNumberValue}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=29", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR04_Select_Flight",LR_AUTO);
	lr_think_time(TNINKTIME);
		
	
	lr_start_transaction("UC01_TR05_Payment_Details");

	web_reg_find("Text=Thank you for booking through Web Tours.",LAST);
	
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value=Lenina", ENDITEM, 
		"Name=address2", "Value=Moscow", ENDITEM, 
		"Name=pass1", "Value={pass1}", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=08/23", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value={flightNumberValue}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=58", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR05_Payment_Details",LR_AUTO);

	return 0;
}
