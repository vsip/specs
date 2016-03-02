########################################################################
#
# Rules to build VSIPL++ specifications.
#
########################################################################

########################################################################
# Variables
########################################################################

vsipl_src:= vsipl.xml acknowledgment.xml glossary.xml intro.xml concepts.xml
vsipl_src+= types.xml support.xml scalar.xml random.xml vector.xml signal.xml
vsipl_src+= linalg.xml io.xml impl.xml

src:=$(vsipl_src)

css:= ../css/style.css
xsl:= ../xsl

specs:= vsipl vsipl-core vsipl-core-light
docs:=$(patsubst %, %.clean, $(specs)) $(patsubst %, %.cb, $(specs))
xhtml_xref:= vsipl.clean.xhtml.xref vsipl.cb.xhtml.xref
fo_xref:= vsipl.clean.fo.xref vsipl.cb.fo.xref
xhtml:= $(docs)
fo:= $(patsubst %, %.fo, $(docs))
pdf:= $(patsubst %, %.pdf, $(docs))

targets:= $(pdf) $(xhtml)

include ../common.mk

debug:
	@echo $(pdf)

all: xhtml pdf

xhtml: $(xhtml)
pdf: $(pdf)

########################################################################
# Dependencies
########################################################################

%.xref: $(vsipl_src)
$(xhtml): $(xhtml_xref)
$(fo): $(fo_xref)

vsipl.clean: vsipl.clean/index.xhtml
vsipl.cb: vsipl.cb/index.xhtml
vsipl-core.clean: vsipl-core.clean/index.xhtml
vsipl-core.cb: vsipl-core.cb/index.xhtml
vsipl-core-light.clean: vsipl-core-light.clean/index.xhtml
vsipl-core-light.cb: vsipl-core-light.cb/index.xhtml
