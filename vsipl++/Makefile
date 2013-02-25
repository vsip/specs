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

docs:= vsipl++ vsipl++-par
xhtml_xref:= vsipl++.xhtml.xref vsipl++-par.xhtml.xref
fo_xref:= vsipl++.fo.xref vsipl++-par.fo.xref
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

vispl++.xhtml.xref: $(vsiplxx_src)
vispl++.fo.xref: $(vsiplxx_src)
vispl++-par.xhtml.xref: $(vsiplxx_par_src)
vispl++-par.fo.xref: $(vsiplxx_par_src)

$(xhtml): $(xhtml_xref)
$(fo): $(fo_xref)

vsipl++: vsipl++/index.xhtml
vsipl++-par: vsipl++-par/index.xhtml
