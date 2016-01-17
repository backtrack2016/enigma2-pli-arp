installdir = $(pkglibdir)/python/Plugins/SystemPlugins

SUBDIRS = SoftwareManager PositionerSetup Satfinder \
	SkinSelector SatelliteEquipmentControl Videomode VideoTune Hotplug \
	DefaultServicesScanner DiseqcTester \
	FastScan OSDPositionSetup OSD3DSetup HdmiCEC VideoClippingSetup \
	VideoEnhancement NetworkWizard VFD-Icons

if ! ENABLE_MINIMAL
SUBDIRS += WirelessLan
endif

if HAVE_TEMPFANCONTROL
SUBDIRS += TempFanControl
endif

endif

if ENABLE_SPARK7162
SUBDIRS += UnionTunerType
install_PYTHON =	\
	__init__.py
