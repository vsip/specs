########################################################################
#
# Common rules and variables to build VSIP specs.
#
########################################################################

xsltproc := xsltproc
fop := /usr/local/apache/fop-1.1/fop

########################################################################
# Build instructions
########################################################################

# Generate XHTML target db
define generate_xhtml_xref
$(xsltproc) --stringparam target.database.document sitemap.xhtml.xml \
  --nonet --xinclude --xincludestyle \
  --stringparam  collect.xref.targets  only  \
  --stringparam targets.filename $@ \
  $(xsl)/xhtml.xsl $< 
endef

# Generate FO target db
define generate_fo_xref
$(xsltproc) --stringparam target.database.document sitemap.fo.xml \
  --nonet --xinclude --xincludestyle \
  --stringparam  collect.xref.targets only \
  --stringparam targets.filename $@ \
  $(xsl)/fo.xsl $< 
endef

# Generate XHTML from DocBook. 
define generate_xhtml
mkdir -p $(@D)
mkdir -p $(@D)/images
cp $(css) $(@D)
cp images/* $(@D)/images/
$(xsltproc) --stringparam target.database.document sitemap.xhtml.xml \
  --nonet --xinclude --output $(@D)/ $(xsl)/xhtml.xsl $<
endef

# Generate XSL-FO from DocBook.
define generate_fo
mkdir -p $(@D)
$(xsltproc) --stringparam target.database.document sitemap.fo.xml \
  --stringparam use.extensions 1 \
  --nonet --xinclude --output $@ $(xsl)/fo.xsl $<
endef

# Generate PDF from XSL-FO.
define generate_pdf
$(fop) $< $@
endef

########################################################################
# Implicit Rules
########################################################################

%.xhtml.xref: %.xml
	$(generate_xhtml_xref)

%/index.xhtml: %.xml $(xsl)/xhtml.xsl $(css)
	$(generate_xhtml)

%.fo.xref: %.xml
	$(generate_fo_xref)

%.fo: %.xml $(xsl)/fo.xsl
	$(generate_fo)

%.pdf: %.fo
	$(generate_pdf)

clean:
	rm -rf $(targets)
	rm -f *.pdf
	rm -f *.fo
	rm -f *.xref
