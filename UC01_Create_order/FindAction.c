FindAction()
{

	char* flightNumberValue = "flightNumberValue";
	char* departValue = "departValue";
	char* arriveValue = "arriveValue";
	
	lr_start_transaction("UC01_TR02_Flights");

	web_reg_save_param("city",
                 "LB=\">",
                 "RB=</option>",
				 "Ord=All",
				 LAST);
	
	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=../WebTours/classes/FormDateUpdate.class", ENDITEM,
		LAST);
		
	lr_save_string(lr_paramarr_random("city"), departValue);
	
	lr_save_string(lr_paramarr_random("city"), arriveValue);

	
	lr_end_transaction("UC01_TR02_Flights",LR_AUTO);

	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR03_Find_Flight");

	web_reg_save_param_regexp("ParamName=flightNumber",
        "RegExp=[0-9]+;[0-9]+;[0-9]+/[0-9]+/[0-9]+",
        "Ordinal=All",
        "Group=0",
        LAST);
	
	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departValue}", ENDITEM,
		"Name=departDate", "Value=11/12/2019", ENDITEM,
		"Name=arrive", "Value={arriveValue}", ENDITEM,
		"Name=returnDate", "Value=11/13/2019", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value=Window", ENDITEM,
		"Name=seatType", "Value=Business", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=18", ENDITEM,
		"Name=findFlights.y", "Value=5", ENDITEM,
		LAST);

	lr_save_string(lr_paramarr_random("flightNumber"), flightNumberValue);

	lr_end_transaction("UC01_TR03_Find_Flight",LR_AUTO);
			
	return 0;
}
