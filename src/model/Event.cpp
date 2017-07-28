/*
 * Copyright 2017 Akshay Agarwal, agarwal.akshay.akshay8@gmail.com
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "Event.h"

#include <Uuid.h>


Event::Event(const char* name,
	const char* place, const char* description,
	bool allday, BDateTime start, BDateTime end,
	const char* id = NULL)
{
	fName = name;
	fPlace = place;
	fDescription = description;
	fAllDay = allday;
	fStart = start;
	fEnd = end;

	if (id == NULL) {
		fId = BUuid().SetToRandom().ToString();
	}
	else
		fId = id;

}


Event::Event(Event& event)
{
	fName = event.GetName();
	fPlace = event.GetPlace();
	fId = event.GetId();
	fDescription = event.GetDescription();
	fAllDay = event.IsAllDay();
	fStart = event.GetStartDateTime();
	fEnd = event.GetEndDateTime();
}


BDateTime
Event::GetStartDateTime()
{
	return fStart;
}


void
Event::SetStartDateTime(BDateTime& start)
{
	fStart = start;
}


BDateTime
Event::GetEndDateTime()
{
	return fEnd;
}


void
Event::SetEndDateTime(BDateTime& end)
{

	fEnd = end;
}


const char*
Event::GetId()
{
	return fId.String();
}


void
Event::SetName(const char* name)
{
	fName = name;
}


const char*
Event::GetName()
{
	return fName.String();
}


void
Event::SetPlace(const char* place)
{
	fPlace = place;
}


const char*
Event::GetPlace()
{
	return fPlace.String();
}

void
Event::SetDescription(const char* description)
{
	fDescription = description;
}


const char*
Event::GetDescription()
{
	return fDescription.String();
}


void
Event::SetAllDay(bool allday)
{
	fAllDay = allday;
}


bool
Event::IsAllDay()
{
	return fAllDay;
}


bool
Event::Equals(Event &e)
{
    return (fId == e.GetId());
}

