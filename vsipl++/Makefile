########################################################################
#
# Rules to build VSIPL++ specifications.
#
########################################################################

########################################################################
# Variables
########################################################################

vsiplxx_src:= vsipl++.xml intro.xml conventions.xml support.xml initfin.xml \
domains.xml block.xml dda.xml views.xml complex.xml math.xml selgen.xml random.xml \
signal.xml changes.xml

vsiplxx_par_src:= vsipl++-par.xml foreword-par.xml intro-par.xml support-par.xml \
map.xml view-par.xml dpp.xml changes-par.xml

src:=$(vsiplxx_src) $(vsiplxx_par_src)

css:= ../css/style.css
xsl:= ../xsl

specs:= vsipl++ vsipl++-par
docs:= $(patsubst %, %.clean, $(specs)) $(patsubst %, %.cb, $(specs))
xhtml_xref:= $(patsubst %, %.xhtml.xref, $(docs))
fo_xref:= $(patsubst %, %.fo.xref, $(docs))
xhtml:= $(docs)
fo:= $(patsubst %, %.fo, $(docs))
pdf:= $(patsubst %, %.pdf, $(docs))

targets:= $(pdf) $(xhtml)

include ../common.mk

all: xhtml pdf

xhtml: $(xhtml)
pdf: $(pdf)

########################################################################
# Dependencies
########################################################################

%.xref: $(vsiplxx_src)
$(xhtml): $(xhtml_xref)
$(fo): $(fo_xref)

vsipl++.clean: vsipl++.clean/index.xhtml
vsipl++.cb: vsipl++.cb/index.xhtml
vsipl++-par.clean: vsipl++-par.clean/index.xhtml
vsipl++-par.cb: vsipl++-par.cb/index.xhtml
