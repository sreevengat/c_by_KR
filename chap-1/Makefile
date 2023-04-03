TOPTARGETS := all clean

SUBDIRS := $(wildcard */.)

$(TOPTARGETS) : $(SUBDIRS)
# continue when errors occrued by using -
$(SUBDIRS):
	-$(MAKE) -C $@ $(MAKECMDGOALS)
.PHONY: $(TOPTARGETS) $(SUBDIRS)
