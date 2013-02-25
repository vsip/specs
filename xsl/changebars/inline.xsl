<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: inline.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:fo="http://www.w3.org/1999/XSL/Format" 
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">
                
  <xsl:template match="d:abbrev |
                       d:accel |
                       d:acronym |
                       d:action |
                       d:application |
                       d:arg |
                       d:attribution |
                       d:biblioref |
                       d:citation |
                       d:citetitle |
                       d:city |
                       d:classname |
                       d:co |
                       d:code |
                       d:command |
                       d:computeroutput |
                       d:confdates |
                       d:confnum |
                       d:confsponsor |
                       d:conftitle |
                       d:constant |
                       d:contractnum |
                       d:contractsponsor |
                       d:contrib |
                       d:copyright |
                       d:coref |
                       d:corpauthor |
                       d:corpcredit |
                       d:corpname |
                       d:country |
                       d:database |
                       d:date |
                       d:edition |
                       d:editor |
                       d:email |
                       d:emphasis |
                       d:entry/text() | 
                       d:envar |
                       d:errorcode |
                       d:errorname |
                       d:errortext |
                       d:errortype |
                       d:exceptionname |
                       d:fax |
                       d:filename |
                       d:firstname |
                       d:firstterm |
                       d:foreignphrase |
                       d:funcdef |
                       d:funcpara |
                       d:function |
                       d:graphic |
                       d:group |
                       d:guibutton |
                       d:guiicon |
                       d:guilabel |
                       d:guimenu |
                       d:guimenuitem | 
                       d:guisubmenu |
                       d:hardware |
                       d:holder |
                       d:honorific |
                       d:initializer |
                       d:inlineequation |
                       d:inlinegraphic |
                       d:inlinemediaobject |
                       d:interface |
                       d:interfacename |
                       d:invpartnumber |
                       d:isbn |
                       d:issn |
                       d:issuenum |
                       d:jobtitle |
                       d:keycap |
                       d:keycode |
                       d:keycombo |
                       d:keysym |
                       d:label |
                       d:literal |
                       d:lineage | 
                       d:lineannotation |
                       d:link |
                       d:manvolnum |
                       d:markup |
                       d:mathphrase |
                       d:medialabel |
                       d:menuchoice |
                       d:methodname |
                       d:methodparam |
                       d:modifier |
                       d:mousebutton |
                       d:msgaud |
                       d:msglevel |
                       d:msgorig |
                       d:msgrel |
                       d:msgsub |
                       d:msgtext |
                       d:olink |
                       d:ooclass |
                       d:ooexception |
                       d:oointerface |
                       d:option |
                       d:optional |
                       d:orgdiv |
                       d:orgname |
                       d:otheraddr |
                       d:othercredit |
                       d:othername |
                       d:package |
                       d:pagenums |
                       d:paramdef |
                       d:parameter |
                       d:personname |
                       d:phone |
                       d:phrase |
                       d:pob |
                       d:postcode |
                       d:productname |
                       d:productnumber |
                       d:prompt |
                       d:property |
                       d:pubdate |
                       d:publishername |
                       d:pubsnumber |
                       d:quote |
                       d:refclass |
                       d:refdescriptor |
                       d:refmiscinfo |
                       d:refname |
                       d:refpurpose |
                       d:remark |
                       d:releaseinfo |
                       d:replaceable |
                       d:returnvalue |
                       d:seriesvolnums |
                       d:sgmltag |
                       d:shortaffil |
                       d:shortcut |
                       d:state |
                       d:street |
                       d:structfield |
                       d:structname |
                       d:subscript |
                       d:superscript |
                       d:surname |
                       d:symbol |
                       d:systemitem |
                       d:td/text() |
                       d:term |
                       d:termdef |
                       d:textdata |
                       d:th/text() |
                       d:token |
                       d:trademark |
                       d:type |
                       d:uri |
                       d:userinput |
                       d:varargs |
                       d:varname |
                       d:void |
                       d:volumenum |
                       d:wordasword |
                       d:xref">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="d:abbrev |
                       d:accel |
                       d:acronym |
                       d:action |
                       d:application |
                       d:arg |
                       d:attribution |
                       d:biblioref |
                       d:citation |
                       d:citetitle |
                       d:city |
                       d:classname |
                       d:co |
                       d:code |
                       d:command |
                       d:computeroutput |
                       d:confdates |
                       d:confnum |
                       d:confsponsor |
                       d:conftitle |
                       d:constant |
                       d:contractnum |
                       d:contractsponsor |
                       d:contrib |
                       d:copyright |
                       d:coref |
                       d:corpauthor |
                       d:corpcredit |
                       d:corpname |
                       d:country |
                       d:database |
                       d:date |
                       d:edition |
                       d:editor |
                       d:email |
                       d:emphasis |
                       d:entry/text() | 
                       d:envar |
                       d:errorcode |
                       d:errorname |
                       d:errortext |
                       d:errortype |
                       d:exceptionname |
                       d:fax |
                       d:filename |
                       d:firstname |
                       d:firstterm |
                       d:foreignphrase |
                       d:funcdef |
                       d:funcpara |
                       d:function |
                       d:graphic |
                       d:group |
                       d:guibutton |
                       d:guiicon |
                       d:guilabel |
                       d:guimenu |
                       d:guimenuitem | 
                       d:guisubmenu |
                       d:hardware |
                       d:holder |
                       d:honorific |
                       d:initializer |
                       d:inlineequation |
                       d:inlinegraphic |
                       d:inlinemediaobject |
                       d:interface |
                       d:interfacename |
                       d:invpartnumber |
                       d:isbn |
                       d:issn |
                       d:issuenum |
                       d:jobtitle |
                       d:keycap |
                       d:keycode |
                       d:keycombo |
                       d:keysym |
                       d:label |
                       d:literal |
                       d:lineage | 
                       d:lineannotation |
                       d:link |
                       d:manvolnum |
                       d:markup |
                       d:mathphrase |
                       d:medialabel |
                       d:menuchoice |
                       d:methodname |
                       d:methodparam |
                       d:modifier |
                       d:mousebutton |
                       d:msgaud |
                       d:msglevel |
                       d:msgorig |
                       d:msgrel |
                       d:msgsub |
                       d:msgtext |
                       d:olink |
                       d:ooclass |
                       d:ooexception |
                       d:oointerface |
                       d:option |
                       d:optional |
                       d:orgdiv |
                       d:orgname |
                       d:otheraddr |
                       d:othercredit |
                       d:othername |
                       d:package |
                       d:pagenums |
                       d:paramdef |
                       d:parameter |
                       d:personname |
                       d:phone |
                       d:phrase |
                       d:pob |
                       d:postcode |
                       d:productname |
                       d:productnumber |
                       d:prompt |
                       d:property |
                       d:pubdate |
                       d:publishername |
                       d:pubsnumber |
                       d:quote |
                       d:refclass |
                       d:refdescriptor |
                       d:refmiscinfo |
                       d:refname |
                       d:refpurpose |
                       d:remark |
                       d:releaseinfo |
                       d:replaceable |
                       d:returnvalue |
                       d:seriesvolnums |
                       d:sgmltag |
                       d:shortaffil |
                       d:shortcut |
                       d:state |
                       d:street |
                       d:structfield |
                       d:structname |
                       d:subscript |
                       d:superscript |
                       d:surname |
                       d:symbol |
                       d:systemitem |
                       d:td/text() |
                       d:term |
                       d:termdef |
                       d:textdata |
                       d:th/text() |
                       d:token |
                       d:trademark |
                       d:type |
                       d:uri |
                       d:userinput |
                       d:varargs |
                       d:varname |
                       d:void |
                       d:volumenum |
                       d:wordasword |
                       d:xref" mode="no.anchor.mode">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:segtitle" mode="segtitle-in-seg">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:*" mode="object.title.markup">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="child::d:title[@revisionflag='added']">
        <fo:inline xsl:use-attribute-sets="added.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:when test="child::d:title[@revisionflag='deleted']">
        <fo:inline xsl:use-attribute-sets="deleted.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="text()[parent::*[@revisionflag='changed']][count(preceding-sibling::*)=0][count(following-sibling::*)=0] | 
                       d:biblioref[@revisionflag='changed']">
    <xsl:variable name="class" select="generate-id()"/>
    <fo:inline xsl:use-attribute-sets="nonwrappable.atts">
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
      </xsl:if>
      <xsl:apply-imports/>
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-end change-bar-class="{$class}"/>
      </xsl:if>
    </fo:inline>
  </xsl:template>
  
  <xsl:template match="text()[parent::*[@revisionflag='changed']][count(preceding-sibling::*)=0][count(following-sibling::*)=0]" mode="bibliography.mode">
    <xsl:variable name="class" select="generate-id()"/>
    <fo:inline xsl:use-attribute-sets="nonwrappable.atts">
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
      </xsl:if>
      <xsl:apply-imports/>
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-end change-bar-class="{$class}"/>
      </xsl:if>
    </fo:inline>
  </xsl:template>
  
  <xsl:template match="text()[parent::*[@revisionflag='changed']][count(preceding-sibling::*)=0][count(following-sibling::*)=0]" mode="bibliomixed.mode">
    <xsl:variable name="class" select="generate-id()"/>
    <fo:inline xsl:use-attribute-sets="nonwrappable.atts">
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
      </xsl:if>
      <xsl:apply-imports/>
      <xsl:if test="$use.changebars != 0">
        <fo:change-bar-end change-bar-class="{$class}"/>
      </xsl:if>
    </fo:inline>
  </xsl:template>

</xsl:stylesheet>