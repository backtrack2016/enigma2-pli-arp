installdir = $(pkglibdir)/python/Plugins/SystemPlugins

SUBDIRS = SoftwareManager PositionerSetup Satfinder \
	SkinSelector SatelliteEquipmentControl Videomode VideoTune Hotplug \
	DefaultServicesScanner DiseqcTester \
	FastScan OSDPositionSetup OSD3DSetup HdmiCEC VideoClippingSetup \
	VideoEnhancement NetworkWizard VFD-Icons

SUBDIRS += WirelessLan

if HAVE_TEMPFANCONTROL
SUBDIRS += TempFanControl
endif

if ENABLE_SPARK7162
SUBDIRS += UnionTunerType
endif

install_PYTHON =	\
	__init__.py
