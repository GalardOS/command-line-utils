# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  basename_config = debug

else ifeq ($(config),release)
  basename_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := basename

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

basename:
ifneq (,$(basename_config))
	@echo "==== Building basename ($(basename_config)) ===="
	@${MAKE} --no-print-directory -C posix/basename -f Makefile config=$(basename_config)
endif

clean:
	@${MAKE} --no-print-directory -C posix/basename -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   basename"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"