<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: changebars.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->

<!-- 
  This stylesheet is used for converting a DocBook document with revisionflags into XSL-FO containing
  text styling to show modifications. It can also produce changebars using XSL-FO 1.1 features.
  Please read the documentation contained in the parent directory for more information on its use.
 -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:fo="http://www.w3.org/1999/XSL/Format" 
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">

  <!-- imports -->
  <xsl:import href="http://docbook.sourceforge.net/release/xsl-ns/current/fo/docbook.xsl"/>
<!--  <xsl:import href="../fo/docbook.xsl"/>-->
  
  <!-- ***IMPORT YOUR DOCBOOK CUSTOMISATIONS HERE*** -->
  <!-- <xsl:import href="/path/to/your/main/xsl/stylesheet"/> -->
  
  <!-- includes -->
  <xsl:include href="inline.xsl"/>
  <xsl:include href="titlepage.xsl"/>
  <xsl:include href="block.xsl"/>
  <xsl:include href="autotoc.xsl"/>
  <xsl:include href="biblio.xsl"/>
  <xsl:include href="overridden-templates.xsl"/>

  <!-- parameters for controlling the fo output -->
  
  <!-- used to specify whether to use XSL-FO 1.1 changebars -->
  <xsl:param name="use.changebars">0</xsl:param>
  <!-- used to specify whether to color text to mark changes -->
  <xsl:param name="use.text.colors">1</xsl:param>
  
  <!-- added text styling params -->
  <xsl:param name="added.color">green</xsl:param>
  <xsl:param name="added.background">inherit</xsl:param>
  <xsl:param name="added.decoration">none</xsl:param>
  <xsl:param name="added.style">italic</xsl:param>
  
  <!-- deleted text styling params -->
  <xsl:param name="deleted.color">red</xsl:param>
  <xsl:param name="deleted.background">inherit</xsl:param>
  <xsl:param name="deleted.decoration">line-through</xsl:param>
  <xsl:param name="deleted.style">normal</xsl:param>
  
  <!-- styling for modified text that occurs in elements that cannot contain <phrase> elements -->
  <xsl:param name="nonwrappable.color">blue</xsl:param>
  <xsl:param name="nonwrappable.background">inherit</xsl:param>
  <xsl:param name="nonwrappable.decoration">underline</xsl:param>
  <xsl:param name="nonwrappable.style">normal</xsl:param>
  
  <!-- changebar properties -->
  <xsl:param name="changebar.color">blue</xsl:param>
  <xsl:param name="changebar.style">solid</xsl:param>
  

  <!-- predefined attribute sets -->
  <xsl:attribute-set name="added.atts">
    <xsl:attribute name="color"><xsl:value-of select="$added.color"/></xsl:attribute>
    <xsl:attribute name="background-color"><xsl:value-of select="$added.background"/></xsl:attribute>
    <xsl:attribute name="text-decoration"><xsl:value-of select="$added.decoration"/></xsl:attribute>
    <xsl:attribute name="font-style"><xsl:value-of select="$added.style"/></xsl:attribute>
  </xsl:attribute-set>
  
  <xsl:attribute-set name="deleted.atts">
    <xsl:attribute name="color"><xsl:value-of select="$deleted.color"/></xsl:attribute>
    <xsl:attribute name="background-color"><xsl:value-of select="$deleted.background"/></xsl:attribute>
    <xsl:attribute name="text-decoration"><xsl:value-of select="$deleted.decoration"/></xsl:attribute>
    <xsl:attribute name="font-style"><xsl:value-of select="$deleted.style"/></xsl:attribute>
  </xsl:attribute-set>
  
  <xsl:attribute-set name="nonwrappable.atts">
    <xsl:attribute name="color">
      <xsl:choose>
        <xsl:when test="$use.text.colors != 0"><xsl:value-of select="$nonwrappable.color"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
      </xsl:attribute>
    <xsl:attribute name="background-color">
      <xsl:choose>
        <xsl:when test="$use.text.colors != 0"><xsl:value-of select="$nonwrappable.background"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="text-decoration">
      <xsl:choose>
        <xsl:when test="$use.text.colors != 0"><xsl:value-of select="$nonwrappable.decoration"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="font-style">
      <xsl:choose>
        <xsl:when test="$use.text.colors != 0"><xsl:value-of select="$nonwrappable.style"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
  </xsl:attribute-set>
  
  <!-- used when we need to add xsl-fo attributes to a current element if it OR an ancestor has a revisionflag -->
  <xsl:attribute-set name="ancestor.revision.atts">
    <xsl:attribute name="color">
      <xsl:choose>
        <xsl:when test="ancestor-or-self::*[@revisionflag='added'] and $use.text.colors != 0"><xsl:value-of select="$added.color"/></xsl:when>
        <xsl:when test="ancestor-or-self::*[@revisionflag='deleted'] and $use.text.colors != 0"><xsl:value-of select="$deleted.color"/></xsl:when>
        <xsl:when test="ancestor-or-self::*[@revisionflag='changed'] and $use.text.colors != 0"><xsl:value-of select="$nonwrappable.color"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="background-color">
      <xsl:choose>
        <xsl:when test="ancestor-or-self::*[@revisionflag='added'] and $use.text.colors != 0"><xsl:value-of select="$added.background"/></xsl:when>
        <xsl:when test="ancestor-or-self::*[@revisionflag='deleted'] and $use.text.colors != 0"><xsl:value-of select="$deleted.background"/></xsl:when>
        <xsl:when test="@revisionflag='changed' and ((count(text())=1 and count(node())=1) or count(node())=0)"><xsl:value-of select="$nonwrappable.background"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="text-decoration">
      <xsl:choose>
        <xsl:when test="ancestor-or-self::*[@revisionflag='added'] and $use.text.colors != 0"><xsl:value-of select="$added.decoration"/></xsl:when>
        <xsl:when test="ancestor-or-self::*[@revisionflag='deleted'] and $use.text.colors != 0"><xsl:value-of select="$deleted.decoration"/></xsl:when>
        <xsl:when test="@revisionflag='changed' and ((count(text())=1 and count(node())=1) or count(node())=0)"><xsl:value-of select="$nonwrappable.decoration"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="font-style">
      <xsl:choose>
        <xsl:when test="ancestor-or-self::*[@revisionflag='added'] and $use.text.colors != 0"><xsl:value-of select="$added.style"/></xsl:when>
        <xsl:when test="ancestor-or-self::*[@revisionflag='deleted'] and $use.text.colors != 0"><xsl:value-of select="$deleted.style"/></xsl:when>
        <xsl:when test="@revisionflag='changed' and ((count(text())=1 and count(node())=1) or count(node())=0)"><xsl:value-of select="$nonwrappable.style"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
  </xsl:attribute-set>
  
  <!-- used when we need to add xsl-fo attributes to a current element if it (NOT an ancestor) has a revisionflag -->
  <xsl:attribute-set name="revision.atts">
    <xsl:attribute name="color">
      <xsl:choose>
        <xsl:when test="@revisionflag='added' and $use.text.colors != 0"><xsl:value-of select="$added.color"/></xsl:when>
        <xsl:when test="@revisionflag='deleted' and $use.text.colors != 0"><xsl:value-of select="$deleted.color"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="background-color">
      <xsl:choose>
        <xsl:when test="@revisionflag='added' and $use.text.colors != 0"><xsl:value-of select="$added.background"/></xsl:when>
        <xsl:when test="@revisionflag='deleted' and $use.text.colors != 0"><xsl:value-of select="$deleted.background"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="text-decoration">
      <xsl:choose>
        <xsl:when test="@revisionflag='added' and $use.text.colors != 0"><xsl:value-of select="$added.decoration"/></xsl:when>
        <xsl:when test="@revisionflag='deleted' and $use.text.colors != 0"><xsl:value-of select="$deleted.decoration"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
    <xsl:attribute name="font-style">
      <xsl:choose>
        <xsl:when test="@revisionflag='added' and $use.text.colors != 0"><xsl:value-of select="$added.style"/></xsl:when>
        <xsl:when test="@revisionflag='deleted' and $use.text.colors != 0"><xsl:value-of select="$deleted.style"/></xsl:when>
        <xsl:otherwise>inherit</xsl:otherwise>
      </xsl:choose>
    </xsl:attribute>
  </xsl:attribute-set>
  
  <xsl:attribute-set name="changebar.atts">
    <xsl:attribute name="change-bar-color"><xsl:value-of select="$changebar.color"/></xsl:attribute>
    <xsl:attribute name="change-bar-style"><xsl:value-of select="$changebar.style"/></xsl:attribute>
  </xsl:attribute-set>

  <!-- items that can be inline OR block but just need changebars so decision is not necessary -->
  <xsl:template match="d:imagedata | d:audiodata | d:videodata">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <!-- open a changebar here if we have set them to be on -->
        <xsl:if test="$use.changebars != 0">
          <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
        </xsl:if>
        <xsl:apply-imports/>
        <!-- close the changebar here if we have set them to be on -->
        <xsl:if test="$use.changebars != 0">
          <fo:change-bar-end change-bar-class="{$class}"/>
        </xsl:if>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

</xsl:stylesheet>
