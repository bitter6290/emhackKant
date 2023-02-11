
MAKEFLAGS += --no-print-directory

TOOLDIRS := $(filter-out tools/mgba tools/agbcc tools/binutils tools/poryscript,$(wildcard tools/*))

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@
