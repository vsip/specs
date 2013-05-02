<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns:d="http://docbook.org/ns/docbook"
                xmlns:fo="http://www.w3.org/1999/XSL/Format"
                version='1.0'>

<!--<xsl:import href="http://docbook.sourceforge.net/release/xsl-ns/current/fo/docbook.xsl"/>-->
<xsl:import href="changebars/changebars.xsl"/>
<xsl:import href="titlepage.templates.xsl"/>

<xsl:template match="processing-instruction('hard-pagebreak')">
  <fo:block break-after='page'/>
</xsl:template>

<xsl:param name="double.sided" select="1"/>
<xsl:param name="target.database.document"></xsl:param>
<xsl:param name="variablelist.as.blocks" select="1"></xsl:param> 
<xsl:param name="section.autolabel" select="1"></xsl:param>

<xsl:attribute-set name="book.titlepage.verso.style" 
		   use-attribute-sets="component.titlepage.properties"/>

<!-- Page number convention:
     * Cover page: no number
     * ToC: new number (roman) 
     * First Chapter: new number (arabic) -->
<xsl:template name="initial.page.number">
  <xsl:param name="element" select="local-name(.)"/>
  <xsl:param name="master-reference" select="''"/>

  <xsl:variable name="first.book.content" 
                select="ancestor::d:book/*[
                          not(self::d:title or
                              self::d:subtitle or
                              self::d:titleabbrev or
                              self::d:bookinfo or
                              self::d:info or
                              self::d:dedication or
                              self::d:acknowledgements or
                              self::d:preface or
                              self::d:toc or
                              self::d:lot)][1]"/>

  <xsl:choose>
    <xsl:when test="$element = 'toc'">1</xsl:when>
        <xsl:when test="generate-id($first.book.content) =
                        generate-id(.)">1</xsl:when>
    <xsl:otherwise>auto</xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="page.number.format">
  <xsl:param name="element" select="local-name(.)"/>
  <xsl:choose>
    <xsl:when test="$element = 'toc'">i</xsl:when>
    <xsl:when test="$element = 'preface'">i</xsl:when>
    <xsl:otherwise>1</xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- Assume document ids are stored in toplevel id attributes -->
<xsl:param name="current.docid" select="/*/@xml:id"/>
<xsl:param name="fop1.extensions" select="1"></xsl:param>
<xsl:param name="insert.olink.pdf.frag" select="1"/>
<xsl:param name="marker.section.level">4</xsl:param>
<xsl:param name="section.label.includes.component.label" select="1"></xsl:param>

<xsl:param name="process.empty.source.toc" select="1"/>
<xsl:param name="generate.toc">book nop</xsl:param>

<!-- Make room for wide markers in the center column of the header -->
<xsl:param name="header.column.widths">0 1 0</xsl:param>
<xsl:param name="tablecolumns.extension" select="0"/>

<!-- Align titles with the item text (we use ordered lists for this) -->
<!--<xsl:param name="title.margin.left">0.5pc</xsl:param>-->
<!--<xsl:attribute-set name="orderedlist.properties">
  <xsl:attribute name=""></xsl:attribute>
</xsl:attribute-set>-->

<!-- Suppress "Chapter" labels in titles and tocs -->
<xsl:param name="local.l10n.xml" select="document('')"/>
<l:i18n xmlns:l="http://docbook.sourceforge.net/xmlns/l10n/1.0">
  <l:l10n language="en">
    <l:context name="title">
      <l:template name="chapter" text="%n. %t"/>
    </l:context>    
    <l:context name="title-numbered">
      <l:template name="chapter" text="%n. %t"/>
    </l:context>    
  </l:l10n>
</l:i18n>

<!-- Exclude prefaces from toc-->
<xsl:template match="d:preface[@xml:id='title1']"  mode="toc" />
<!--<xsl:template match="d:preface[@xml:id='title2']"  mode="toc" />-->
<xsl:template match="d:preface[@xml:id='legalnotice']"  mode="toc" />

<!-- Don't print title page prefaces a second time -->
<xsl:template match="d:preface[@xml:id='title1']"/>
<!--<xsl:template match="d:preface[@xml:id='title2']"/>-->
<xsl:template match="d:preface[@xml:id='legalnotice']"/>

<!-- Insert ':' between 'Publication date' and the actual date -->
<xsl:template match="d:bookinfo/d:pubdate|d:book/d:info/d:pubdate"
              mode="titlepage.mode" priority="2">
  <fo:block>
    <xsl:call-template name="gentext">
      <xsl:with-param name="key" select="'pubdate'"/>
    </xsl:call-template>
    <xsl:text>: </xsl:text>
    <xsl:apply-templates mode="titlepage.mode"/>
  </fo:block>
</xsl:template>


<!--
Put a box around code blocks, also set the font size
and keep the block together if we can using the widows 
and orphans controls.  Hyphenation and line wrapping
is also turned on, so that long lines of code don't
bleed off the edge of the page, a carriage return
symbol is used as the hyphenation character:
-->
<xsl:attribute-set name="monospace.verbatim.properties">
  <xsl:attribute name="border-color">#DCDCDC</xsl:attribute>
  <xsl:attribute name="border-width">1px</xsl:attribute>
  <xsl:attribute name="border-style">solid</xsl:attribute>
  <xsl:attribute name="padding-left">0.2cm</xsl:attribute>
  <xsl:attribute name="padding-right">0.2cm</xsl:attribute>
  <xsl:attribute name="padding-top">0.2cm</xsl:attribute>
  <xsl:attribute name="padding-bottom">0.2cm</xsl:attribute>
  <xsl:attribute name="widows">6</xsl:attribute>
  <xsl:attribute name="orphans">40</xsl:attribute>
  <xsl:attribute name="font-size">8pt</xsl:attribute>
  <xsl:attribute name="hyphenate">true</xsl:attribute>
<!-- This attribute triggers a bug in fop -->
<!--  <xsl:attribute name="wrap-option">wrap</xsl:attribute>-->
<!--  <xsl:attribute name="hyphenation-character">&#x21B5;</xsl:attribute>-->
  <xsl:attribute name="margin-left">0pt</xsl:attribute>
  <xsl:attribute name="margin-right">0pt</xsl:attribute>
</xsl:attribute-set>

<xsl:attribute-set name="chapter.title.properties" 
		   use-attribute-sets="component.title.properties">
  <xsl:attribute name="border-top">0.5pt solid black</xsl:attribute>
  <xsl:attribute name="border-bottom">0.5pt solid black</xsl:attribute>
  <xsl:attribute name="padding-top">6pt</xsl:attribute>
  <xsl:attribute name="padding-bottom">24pt</xsl:attribute>
  <xsl:attribute name="margin-top">6pt</xsl:attribute>
  <xsl:attribute name="margin-bottom">24pt</xsl:attribute>
  <!--<xsl:attribute name="font-weight">normal</xsl:attribute>-->
  <!--<xsl:attribute name="font-size">italic</xsl:attribute>-->
  <xsl:attribute name="font-size">
    <xsl:value-of select="$body.font.master"/>
    <xsl:text>pt</xsl:text>
  </xsl:attribute>
</xsl:attribute-set>

<!--<xsl:attribute-set name="section.title.properties" 
		   use-attribute-sets="component.title.properties">
  <xsl:attribute name="font-style">italic</xsl:attribute>
  <xsl:attribute name="font-weight">normal</xsl:attribute>
</xsl:attribute-set>-->

<xsl:attribute-set name="revhistory.title.properties">
  <xsl:attribute name="font-size">12pt</xsl:attribute>
  <xsl:attribute name="font-weight">bold</xsl:attribute>
  <xsl:attribute name="text-align">center</xsl:attribute>
</xsl:attribute-set>

<xsl:attribute-set name="revhistory.table.properties">
  <xsl:attribute name="border">0.5pt solid black</xsl:attribute>
</xsl:attribute-set>

<xsl:attribute-set name="formal.title.properties">
  <xsl:attribute name="font-size">9pt</xsl:attribute>
</xsl:attribute-set>

<xsl:attribute-set name="revhistory.table.cell.properties">
  <xsl:attribute name="border">0.5pt solid black</xsl:attribute>
  <xsl:attribute name="font-size">9pt</xsl:attribute>
  <xsl:attribute name="padding">4pt</xsl:attribute>
</xsl:attribute-set>

<xsl:template match="d:revision/d:date">
  Approved: <xsl:apply-templates />
</xsl:template>

<!-- Generate a (chapter or section) title -->
<xsl:template name="vsiplxx.heading">
  <xsl:param name="title"/>
  <xsl:param name="titleabbrev"/>
  <fo:table>
    <fo:table-column column-number="1"/>
    <fo:table-column column-number="2"/>
    <fo:table-body>
      <fo:table-row>
	<fo:table-cell>
	  <fo:block xsl:use-attribute-sets="section.title.properties">
	    <xsl:copy-of select="$title"/>
	  </fo:block>
	</fo:table-cell>
	<fo:table-cell text-align="right">
	  <fo:block font-weight="bold" font-style="normal">
	    <xsl:if test="$titleabbrev">
	      [<xsl:value-of select="$titleabbrev"/>]
	    </xsl:if>
	  </fo:block>
	</fo:table-cell>
      </fo:table-row>
    </fo:table-body>
  </fo:table>
</xsl:template>

<!-- Define chapter title formatting -->
<xsl:template name="chapter.title">
  <xsl:param name="node" select="."/>
  <xsl:param name="pagewide" select="0"/>

  <xsl:variable name="id">
    <xsl:call-template name="object.id">
      <xsl:with-param name="object" select="$node"/>
    </xsl:call-template>
  </xsl:variable>

  <xsl:variable name="title">
    <xsl:apply-templates select="$node" mode="object.title.markup">
      <xsl:with-param name="allow-anchors" select="1"/>
    </xsl:apply-templates>
  </xsl:variable>

  <xsl:variable name="titleabbrev">
    <xsl:apply-templates select="$node" mode="titleabbrev.markup"/>
  </xsl:variable>

  <fo:block xsl:use-attribute-sets="chapter.title.properties">
    <xsl:if test="$pagewide != 0">
      <!-- Doesn't work to use 'all' here since not a child of fo:flow -->
      <xsl:attribute name="span">inherit</xsl:attribute>
    </xsl:if>
    <xsl:attribute name="hyphenation-character">
      <xsl:call-template name="gentext">
        <xsl:with-param name="key" select="'hyphenation-character'"/>
      </xsl:call-template>
    </xsl:attribute>
    <xsl:attribute name="hyphenation-push-character-count">
      <xsl:call-template name="gentext">
        <xsl:with-param name="key" select="'hyphenation-push-character-count'"/>
      </xsl:call-template>
    </xsl:attribute>
    <xsl:attribute name="hyphenation-remain-character-count">
      <xsl:call-template name="gentext">
        <xsl:with-param name="key" select="'hyphenation-remain-character-count'"/>
      </xsl:call-template>
    </xsl:attribute>

    <xsl:choose>
      <xsl:when test="local-name() = 'preface'">
	<xsl:copy-of select="$title"/>
      </xsl:when>
      <xsl:otherwise>
	<xsl:call-template name="vsiplxx.heading">
	  <xsl:with-param name="title" select="$title"/>
	  <xsl:with-param name="titleabbrev" select="$titleabbrev"/>
	</xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </fo:block>
</xsl:template>

<xsl:template match="d:chapter/d:title" mode="chapter.titlepage.recto.auto.mode">  
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" 
            xsl:use-attribute-sets="chapter.titlepage.recto.style" 
            margin-left="{$title.margin.left}" 
            font-size="24.8832pt" 
            font-weight="bold" 
            font-family="{$title.font.family}">
    <xsl:call-template name="chapter.title">
      <xsl:with-param name="node" select="ancestor-or-self::d:chapter[1]"/>
    </xsl:call-template>
  </fo:block>
</xsl:template>

<!-- Define section heading to display title on the left and titleabbrev on the right-->
<xsl:template name="section.heading">
  <xsl:param name="level" select="1"/>
  <xsl:param name="marker" select="1"/>
  <xsl:param name="title"/>
  <xsl:param name="marker.title"/>

  <xsl:variable name="titleabbrev" select="ancestor::d:section[1]/d:titleabbrev"/>

  <fo:block xsl:use-attribute-sets="section.title.properties">
    <xsl:if test="$marker != 0">
      <fo:marker marker-class-name="section.head.marker">
        <xsl:copy-of select="$marker.title"/>
      </fo:marker>
    </xsl:if>
    <xsl:call-template name="vsiplxx.heading">
      <xsl:with-param name="title" select="$title"/>
      <xsl:with-param name="titleabbrev" select="$titleabbrev"/>
    </xsl:call-template>
  </fo:block>
</xsl:template>

<!-- Spec items don't use punctuation -->
<xsl:template match="d:chapter/d:orderedlist/d:listitem
                    |d:section/d:orderedlist/d:listitem"
	      mode="item-number">
  <xsl:variable name="item-number">
    <xsl:call-template name="orderedlist-item-number"/>
  </xsl:variable>
  <xsl:number value="$item-number" format="1"/>
</xsl:template>

<!-- Generate appropriate spec reference labels -->
<xsl:template match="d:section" mode="xref-to">
  <xsl:param name="referrer"/>
  <xsl:param name="xrefstyle"/>
  [<xsl:value-of select="d:titleabbrev"/>]
</xsl:template>

<!-- This naming style assumes that a section has at most one 
     orderedlist child. -->
<xsl:template match="d:section/d:orderedlist/d:listitem" mode="xref-to">
  <xsl:param name="referrer"/>
  <xsl:param name="xrefstyle"/>
  [<xsl:value-of select="ancestor::d:section/d:titleabbrev"/>]/<xsl:copy-of select="count(preceding-sibling::d:listitem) + 1"/>
</xsl:template>

<!-- No header rule for chapter titlepages -->
<xsl:template name="head.sep.rule">
  <xsl:param name="pageclass"/>
  <xsl:param name="sequence"/>
  <xsl:param name="gentext-key"/>
  <xsl:if test="$pageclass != 'titlepage'">
    <xsl:if test="$sequence != 'first'">
      <xsl:attribute name="border-bottom-width">0.5pt</xsl:attribute>
      <xsl:attribute name="border-bottom-style">solid</xsl:attribute>
      <xsl:attribute name="border-bottom-color">black</xsl:attribute>
    </xsl:if>
  </xsl:if>
</xsl:template>

<!-- No footer rule for titlepages -->
<xsl:template name="foot.sep.rule">
  <xsl:param name="pageclass"/>
  <xsl:param name="sequence"/>
  <xsl:param name="gentext-key"/>
  <xsl:if test="$pageclass != 'titlepage'">
    <xsl:attribute name="border-top-width">0.5pt</xsl:attribute>
    <xsl:attribute name="border-top-style">solid</xsl:attribute>
    <xsl:attribute name="border-top-color">black</xsl:attribute>
  </xsl:if>
</xsl:template>

<!-- Put the marker into the header, even for double-sided output -->
<xsl:template name="header.content">
  <xsl:param name="pageclass" select="''"/>
  <xsl:param name="sequence" select="''"/>
  <xsl:param name="position" select="''"/>
  <xsl:param name="gentext-key" select="''"/>

  <fo:block>

    <!-- sequence can be odd, even, first, blank -->
    <!-- position can be left, center, right -->
      <xsl:if test="($sequence='odd' or $sequence='even') and $position='center'">
        <xsl:if test="$pageclass != 'titlepage'">
	  <fo:retrieve-marker retrieve-class-name="section.head.marker"
			      retrieve-position="first-including-carryover"
			      retrieve-boundary="page-sequence"/>
        </xsl:if>
      </xsl:if>
  </fo:block>
</xsl:template>

<xsl:template name="footer.content">
  <xsl:param name="pageclass" select="''"/>
  <xsl:param name="sequence" select="''"/>
  <xsl:param name="position" select="''"/>
  <xsl:param name="gentext-key" select="''"/>

<!--
  <fo:block>
    <xsl:value-of select="$pageclass"/>
    <xsl:text>, </xsl:text>
    <xsl:value-of select="$sequence"/>
    <xsl:text>, </xsl:text>
    <xsl:value-of select="$position"/>
    <xsl:text>, </xsl:text>
    <xsl:value-of select="$gentext-key"/>
  </fo:block>
-->

  <fo:block>
    <!-- pageclass can be front, body, back -->
    <!-- sequence can be odd, even, first, blank -->
    <!-- position can be left, center, right -->
    <xsl:choose>
      <xsl:when test="$pageclass = 'titlepage'">
        <!-- nop; no footer on title pages -->
      </xsl:when>

      <xsl:when test="$double.sided != 0 and $sequence = 'even'
                      and $position='left'">
        <fo:page-number/>
      </xsl:when>
      <xsl:when test="$double.sided != 0 and $sequence = 'even'
                      and $position='right'">
        <xsl:value-of select="/d:book/d:info/d:titleabbrev"/>
      </xsl:when>

      <xsl:when test="$double.sided != 0 and ($sequence = 'odd' or $sequence = 'first')
                      and $position='right'">
        <fo:page-number/>
      </xsl:when>
      <xsl:when test="$double.sided != 0 and ($sequence = 'odd' or $sequence = 'first')
                      and $position='left'">
        <xsl:value-of select="/d:book/d:info/d:titleabbrev"/>
      </xsl:when>

      <xsl:when test="$double.sided = 0 and $position='center'">
        <fo:page-number/>
      </xsl:when>

      <xsl:when test="$sequence='blank'">
        <xsl:choose>
          <xsl:when test="$double.sided != 0 and $position = 'left'">
            <fo:page-number/>
          </xsl:when>
          <xsl:when test="$double.sided = 0 and $position = 'center'">
            <fo:page-number/>
          </xsl:when>
          <xsl:otherwise>
            <!-- nop -->
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>


      <xsl:otherwise>
        <!-- nop -->
      </xsl:otherwise>
    </xsl:choose>
  </fo:block>
</xsl:template>

<!-- Customize to set another marker -->
<xsl:template match="d:section/d:title
                     |d:simplesect/d:title
                     |d:section/d:info/d:title
                     |d:simplesect/d:info/d:title
                     |d:section/d:sectioninfo/d:title"
              mode="titlepage.mode">

  <xsl:variable name="section" 
                select="(ancestor::d:section |
                        ancestor::d:simplesect)[position() = last()]"/>

  <fo:block keep-with-next.within-column="always">
    <xsl:variable name="id">
      <xsl:call-template name="object.id">
        <xsl:with-param name="object" select="$section"/>
      </xsl:call-template>
    </xsl:variable>

    <xsl:variable name="level">
      <xsl:call-template name="section.level">
	<xsl:with-param name="node" select="$section"/>
      </xsl:call-template>
    </xsl:variable>

    <xsl:variable name="marker">
      <xsl:choose>
        <xsl:when test="$level &lt;= $marker.section.level">1</xsl:when>
        <xsl:otherwise>0</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>

    <xsl:variable name="title">
      <xsl:apply-templates select="$section" mode="object.title.markup">
        <xsl:with-param name="allow-anchors" select="1"/>
      </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="label">
      <xsl:apply-templates select="$section" mode="label.markup"/>
    </xsl:variable>
    <xsl:variable name="titleabbrev">
      <xsl:apply-templates select="$section" mode="titleabbrev.markup"/>
    </xsl:variable>

    <xsl:variable name="marker.title">
      <xsl:value-of select="$label"/> [<xsl:value-of select="$titleabbrev"/>]
    </xsl:variable>

    <xsl:call-template name="section.heading">
      <xsl:with-param name="level" select="$level"/>
      <xsl:with-param name="title" select="$title"/>
      <xsl:with-param name="marker" select="$marker"/>
      <xsl:with-param name="marker.title" select="$marker.title"/>
    </xsl:call-template>
  </fo:block>
</xsl:template>

<xsl:template match="d:function/d:replaceable">
  <xsl:call-template name="inline.italicmonoseq"/>
</xsl:template>


<xsl:template match="*[@role='not.in.toc']" mode="fop1.outline"/>

<!-- Hack: make certain table cells smaller to avoid overflowing boxes -->
<xsl:template name="table.cell.block.properties">
  <!-- highlight this entry? -->
  <xsl:choose>
    <xsl:when test="ancestor::d:thead or ancestor::d:tfoot">
      <xsl:attribute name="font-weight">bold</xsl:attribute>
    </xsl:when>
    <!-- Make row headers bold too -->
    <xsl:when test="ancestor::d:tbody and 
                    (ancestor::d:table[@rowheader = 'firstcol'] or
                    ancestor::d:informaltable[@rowheader = 'firstcol']) and
                    ancestor-or-self::d:entry[1][count(preceding-sibling::d:entry) = 0]">
      <xsl:attribute name="font-weight">bold</xsl:attribute>
    </xsl:when>
    <!-- Look for role="smaller" -->
    <xsl:when test="ancestor::d:tbody and 
                    (ancestor::d:table[@role = 'smaller'] or
                    ancestor::d:informaltable[@role = 'smaller'])">
      <xsl:attribute name="font-size">70%</xsl:attribute>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<!-- Only left-justify varlist entries. They tend to contain short paragraphs
     with lengthy words (such as function names), causing spaces to be stretched
     a lot if lines are justified to both sides. -->
<xsl:template match="d:varlistentry/d:listitem">

  <fo:block text-align="left">
    <xsl:apply-templates/>
  </fo:block>

<!--  <xsl:variable name="term">
    <xsl:value-of select="preceding-sibling::node()[1]"/>
  </xsl:variable>
  <xsl:choose>
    <xsl:when test="$term='See Also'">
      <fo:block text-align="left">
	<xsl:apply-templates/>
      </fo:block>
    </xsl:when>
    <xsl:otherwise>
      <xsl:apply-templates/>
    </xsl:otherwise>
  </xsl:choose> -->

</xsl:template>

</xsl:stylesheet>
