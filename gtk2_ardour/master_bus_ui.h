/*
	Copyright (C) 2014 Waves Audio Ltd.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __tracks_master_bus_ui_h__
#define __tracks_master_bus_ui_h__

#include <list>
#include <set>

#include <gtkmm/table.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/radiomenuitem.h>
#include <gtkmm/checkmenuitem.h>
#include <gtkmm/adjustment.h>

#include <gtkmm2ext/selector.h>
#include <gtkmm2ext/slider_controller.h>

#include "ardour/playlist.h"
#include "ardour/types.h"

#include "route_ui.h"
#include "enums.h"
#include "gain_meter.h"

class MasterBusUI : public Gtk::EventBox, public WavesUI
{
public:
 	MasterBusUI (ARDOUR::Session*);
 	virtual ~MasterBusUI ();

    void fast_update ();
	void set_route (boost::shared_ptr<ARDOUR::Route>);
	static PBD::Signal1<void,MasterBusUI*> CatchDeletion;

private:
	static int __meter_width;
	float _max_peak;
	float _peak_treshold;

 	void reset ();
	void meter_configuration_changed (ARDOUR::ChanCount);
	void reset_peak_display ();
	void reset_route_peak_display (ARDOUR::Route* route);
	void reset_group_peak_display (ARDOUR::RouteGroup* group);
	void on_peak_display_button (WavesButton*);
	void on_master_mute_button (WavesButton*);
	void on_clear_solo_button (WavesButton*);
	void on_global_rec_button (WavesButton*);

	boost::shared_ptr<ARDOUR::Route> _route;
	PBD::ScopedConnectionList _route_connections;

	Gtk::Box& _level_meter_home;
	LevelMeterHBox _level_meter;
	WavesButton& _peak_display_button;
	WavesButton& _master_mute_button;
	WavesButton& _clear_solo_button;
	WavesButton& _global_rec_button;
};

#endif /* __tracks_master_bus_ui_h__ */

