<?xml version="1.0"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:d="http://docbook.org/ns/docbook"
xmlns:exsl="http://exslt.org/common" version="1.0" exclude-result-prefixes="exsl d">

<!-- This stylesheet was created by template/titlepage.xsl-->

<xsl:template mode="book.titlepage.recto.auto.mode" match="d:preface[@xml:id='title1']">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format"
	    border-top="3pt solid black"
	    border-bottom="3pt solid black"
	    padding-before="10mm"
	    padding-after="10mm">
    <xsl:apply-templates select="d:para"/>
  </fo:block>
</xsl:template>

<xsl:template mode="book.titlepage.recto.auto.mode" match="d:preface[@xml:id='title2']">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <!-- Hack: DB5 requires prefaces to have titles, but we really don't want one here. -->
    <xsl:apply-templates select="d:para" />
  </fo:block>
</xsl:template>

<xsl:template name="book.titlepage.recto">
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:pubdate"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:corpauthor"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:corpauthor"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:authorgroup"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:authorgroup"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:author"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:author"/>
  <xsl:choose>
    <xsl:when test="d:bookinfo/d:title">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:title"/>
    </xsl:when>
    <xsl:when test="d:info/d:title">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:title"/>
    </xsl:when>
    <xsl:when test="d:title">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:title"/>
    </xsl:when>
  </xsl:choose>

  <xsl:choose>
    <xsl:when test="d:bookinfo/d:subtitle">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:subtitle"/>
    </xsl:when>
    <xsl:when test="d:info/d:subtitle">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:subtitle"/>
    </xsl:when>
    <xsl:when test="d:subtitle">
      <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:subtitle"/>
    </xsl:when>
  </xsl:choose>

  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:bookinfo/d:releaseinfo"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" select="d:info/d:releaseinfo"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" 
		       select="d:preface[@xml:id='title1']"/>
  <xsl:apply-templates mode="book.titlepage.recto.auto.mode" 
		       select="d:preface[@xml:id='title2']"/>
</xsl:template>

<!-- Put the content of a 'legalnotice' preface into the verso titlepage -->
<xsl:template name="book.titlepage.verso">
  <xsl:apply-templates select="d:preface[@xml:id='legalnotice']/*" />
</xsl:template>

<xsl:template name="book.titlepage">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:variable name="recto.content">
      <xsl:call-template name="book.titlepage.before.recto"/>
      <xsl:call-template name="book.titlepage.recto"/>
    </xsl:variable>
    <xsl:variable name="recto.elements.count">
      <xsl:choose>
        <xsl:when test="function-available('exsl:node-set')"><xsl:value-of select="count(exsl:node-set($recto.content)/*)"/></xsl:when>
        <xsl:when test="contains(system-property('xsl:vendor'), 'Apache Software Foundation')">
          <!--Xalan quirk--><xsl:value-of select="count(exsl:node-set($recto.content)/*)"/></xsl:when>
        <xsl:otherwise>1</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:if test="(normalize-space($recto.content) != '') or ($recto.elements.count &gt; 0)">
      <fo:block><xsl:copy-of select="$recto.content"/></fo:block>
    </xsl:if>
    <xsl:variable name="verso.content">
      <xsl:call-template name="book.titlepage.before.verso"/>
      <xsl:call-template name="book.titlepage.verso"/>
    </xsl:variable>
    <xsl:variable name="verso.elements.count">
      <xsl:choose>
        <xsl:when test="function-available('exsl:node-set')"><xsl:value-of select="count(exsl:node-set($verso.content)/*)"/></xsl:when>
        <xsl:when test="contains(system-property('xsl:vendor'), 'Apache Software Foundation')">
          <!--Xalan quirk--><xsl:value-of select="count(exsl:node-set($verso.content)/*)"/></xsl:when>
        <xsl:otherwise>1</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:if test="(normalize-space($verso.content) != '') or ($verso.elements.count &gt; 0)">
      <fo:block><xsl:copy-of select="$verso.content"/></fo:block>
    </xsl:if>
    <xsl:call-template name="book.titlepage.separator"/>
  </fo:block>
</xsl:template>

<xsl:template match="*" mode="book.titlepage.recto.mode">
  <!-- if an element isn't found in this mode, -->
  <!-- try the generic titlepage.mode -->
  <xsl:apply-templates select="." mode="titlepage.mode"/>
</xsl:template>

<xsl:template match="*" mode="book.titlepage.verso.mode">
  <!-- if an element isn't found in this mode, -->
  <!-- try the generic titlepage.mode -->
  <xsl:apply-templates select="." mode="titlepage.mode"/>
</xsl:template>

<!-- Make sure the footnote shows up.-->
<xsl:template match="d:title" mode="book.titlepage.recto.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.recto.style" text-align="left" font-size="24.8832pt" space-before="18.6624pt" space-after="10mm" font-weight="bold" font-family="{$title.fontset}">
<!--<xsl:call-template name="division.title">
<xsl:with-param name="node" select="ancestor-or-self::d:book[1]"/>
</xsl:call-template>-->
<fo:block>
    <xsl:apply-templates mode="titlepage.mode"/>
</fo:block>
</fo:block>
</xsl:template>

<xsl:template match="d:subtitle" mode="book.titlepage.recto.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.recto.style" text-align="left" font-size="20.736pt" space-before="15.552pt" space-after="20mm" font-family="{$title.fontset}">
<xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:corpauthor" mode="book.titlepage.recto.auto.mode">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
  </fo:block>
</xsl:template>

<xsl:template match="d:authorgroup" mode="book.titlepage.recto.auto.mode">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" text-align="left">
    <xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
  </fo:block>
</xsl:template>

<xsl:template match="d:author" mode="book.titlepage.recto.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.recto.style" font-size="17.28pt" space-before="10.8pt" keep-with-next.within-column="always">
<xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:title" mode="book.titlepage.verso.auto.mode">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.verso.style">
    <xsl:call-template name="book.verso.title">
    </xsl:call-template>
  </fo:block>
</xsl:template>

<xsl:template match="d:releaseinfo" mode="book.titlepage.recto.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.recto.style" space-before="0.5em">
<xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:pubdate" mode="book.titlepage.recto.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.recto.style" space-before="1em" text-align="right">
<xsl:apply-templates select="." mode="book.titlepage.recto.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:copyright" mode="book.titlepage.verso.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.verso.style">
<xsl:apply-templates select="." mode="book.titlepage.verso.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:abstract" mode="book.titlepage.verso.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.verso.style">
<xsl:apply-templates select="." mode="book.titlepage.verso.mode"/>
</fo:block>
</xsl:template>

<xsl:template match="d:legalnotice" mode="book.titlepage.verso.auto.mode">
<fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="book.titlepage.verso.style" font-size="8pt">
<xsl:apply-templates select="." mode="book.titlepage.verso.mode"/>
</fo:block>
</xsl:template>

<!-- Adjust the preface title style to be the same as for chapter titles -->
<xsl:template name="preface.titlepage.recto">
  <fo:block xmlns:fo="http://www.w3.org/1999/XSL/Format" xsl:use-attribute-sets="preface.titlepage.recto.style" margin-left="{$title.margin.left}" font-size="24.8832pt" font-family="{$title.fontset}" font-weight="bold">
    <xsl:call-template name="chapter.title">
      <xsl:with-param name="node" select="ancestor-or-self::d:preface[1]"/>
    </xsl:call-template>
  </fo:block>
  <xsl:choose>
    <xsl:when test="d:prefaceinfo/d:subtitle">
      <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:subtitle"/>
    </xsl:when>
    <xsl:when test="d:docinfo/d:subtitle">
      <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:subtitle"/>
    </xsl:when>
    <xsl:when test="d:info/d:subtitle">
      <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:subtitle"/>
    </xsl:when>
    <xsl:when test="d:subtitle">
      <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:subtitle"/>
    </xsl:when>
  </xsl:choose>

  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:corpauthor"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:corpauthor"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:corpauthor"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:authorgroup"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:authorgroup"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:authorgroup"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:author"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:author"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:author"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:othercredit"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:othercredit"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:othercredit"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:releaseinfo"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:releaseinfo"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:releaseinfo"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:copyright"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:copyright"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:copyright"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:legalnotice"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:legalnotice"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:legalnotice"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:pubdate"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:pubdate"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:pubdate"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:revision"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:revision"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:revision"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:revhistory"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:revhistory"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:revhistory"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:prefaceinfo/d:abstract"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:docinfo/d:abstract"/>
  <xsl:apply-templates mode="preface.titlepage.recto.auto.mode" select="d:info/d:abstract"/>
</xsl:template>

</xsl:stylesheet>

