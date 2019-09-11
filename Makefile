
DIRS = lecture01 lecture02 lecture03 lecture04 lecture05

.PHONY = $(addsuffix -all,$(DIRS)) $(addsuffix -test,$(DIRS)) $(addsuffix -test,$(DIRS))

all: $(addsuffix -all,$(DIRS))

test: all $(addsuffix -test,$(DIRS))

clean: $(addsuffix -clean,$(DIRS))

$(addsuffix -all,$(DIRS)):
	make -C $(subst -all,,$@) all

$(addsuffix -test,$(DIRS)):
	make -C $(subst -test,,$@) test

$(addsuffix -clean,$(DIRS)):
	make -C $(subst -clean,,$@) clean
