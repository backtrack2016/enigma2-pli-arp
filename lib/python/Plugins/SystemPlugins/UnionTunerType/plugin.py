from Screens.Screen import Screen
from Screens.Standby import TryQuitMainloop
from Screens.MessageBox import MessageBox
from Components.ActionMap import ActionMap
from Components.config import getConfigListEntry, ConfigSelection
from Components.ConfigList import ConfigListScreen
from Components.Sources.StaticText import StaticText
from Plugins.Plugin import PluginDescriptor
from os import path as os_path

option = 'options spark7162 UnionTunerType='
filename = '/etc/modprobe.d/tunertype.conf'

class UnionTunerType(Screen, ConfigListScreen):

	def __init__(self, session):
		self.session = session
		Screen.__init__(self, self.session)
		self.skinName = ["Setup"]
		self.setTitle(_("Amiko alien2 select tuner mode"))
		self["actions"] = ActionMap(["SetupActions", "ColorActions"],
			{
				"cancel": self.cancel,
				"ok": self.ok,
				"green": self.ok,
				"red": self.cancel,
			}, -2)

		t = None
		if os_path.exists(filename):
			settings = open(filename)
			while True:
				s = settings.readline().strip()
				if s == '':
					break
				if s.startswith(option):
					try:
						t = s[len(option)]
					except IndexError:
						print '[UnionTunerType] bad format in modprobe config'
					break
			settings.close()
		if t is None:
			t = 't'

		self.tunerconfig = ConfigSelection(default = t, choices = [ ('t', _("terrestrial")) , ('c', _("cable")) ])
		conf = []
		conf.append(getConfigListEntry(_("UnionTunerType"), self.tunerconfig))
		ConfigListScreen.__init__(self, conf, session = self.session)
		self["key_red"] = StaticText(_("Cancel"))
		self["key_green"] = StaticText(_("OK"))

	def settingsWrite(self, result):
		if result is not None and result:
			settings = open(filename, 'w')
			settings.write(option + self.tunerconfig.value + '\n')
			settings.close()
			self.session.open(TryQuitMainloop,retvalue=2)
		self.close()

	def ok(self):
		if self.tunerconfig.isChanged():
			self.session.openWithCallback(self.settingsWrite, MessageBox,
			  (_("Are you sure to save the current configuration and reboot your receiver?\n\n") ))
		else:
			self.close()

	def cancel(self):
		self.close()

def main(session, **kwargs):
	session.open(UnionTunerType)

def menu(menuid, **kwargs):
	if menuid == "scan":
		return [(_("UnionTunerType config"), main, "UnionTunerType", None)]
	else:
		return []

def Plugins(**kwargs):
	return PluginDescriptor(name=_("UnionTunerType config"), description="Select amiko alien2 dvb-t/c tuner mode", where = PluginDescriptor.WHERE_MENU, fnc=menu)
