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

docs:= vsipl vsipl-core vsipl-core-light
xhtml_xref:= vsipl.xhtml.xref
fo_xref:= vsipl.fo.xref
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

vispl.xhtml.xref: $(vsipl_src)
vispl.fo.xref: $(vsipl_src)

$(xhtml): $(xhtml_xref)
$(fo): $(fo_xref)

vsipl: vsipl/index.xhtml
vsipl-core: vsipl-core/index.xhtml
vsipl-core-light: vsipl-core-light/index.xhtml
