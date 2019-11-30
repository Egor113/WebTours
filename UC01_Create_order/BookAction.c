BookAction()
{
	
	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR04_Select_Flight");

	web_submit_data("reservations.pl_2", 
		"Action={Host}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/reservations.pl", 
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
		"Action={Host}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Address1}", ENDITEM, 
		"Name=address2", "Value={Address2}", ENDITEM, 
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value={ExpDate}", ENDITEM, 
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
