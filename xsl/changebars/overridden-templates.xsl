<?xml version="1.0" encoding="UTF-8"?>
<!-- $Id: overridden-templates.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<!-- This file contains templates taken from stylesheets that are part of DocBook XSL (http://docbook.sourceforge.net)
     Tey have been modified for use in this customisation and are clearly marked where this is the case. They remain subject
     to the restrictions imposed by the DocBook XSL license.
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:fo="http://www.w3.org/1999/XSL/Format"
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">

  <!-- need to override this template so that an added or deleted bibliography has a solid changebar over the whole bibliography -->
  <!-- original template from fo/biblio.xsl -->
  <xsl:template match="bibliography">
    <xsl:variable name="id">
      <xsl:call-template name="object.id"/>
    </xsl:variable>
    
    <xsl:choose>
      <xsl:when test="not(parent::*) or parent::d:part or parent::d:book">
        <xsl:variable name="master-reference">
          <xsl:call-template name="select.pagemaster"/>
        </xsl:variable>
        
        <fo:page-sequence hyphenate="{$hyphenate}"
          master-reference="{$master-reference}">
          <xsl:attribute name="language">
            <xsl:call-template name="l10n.language"/>
          </xsl:attribute>
          <xsl:attribute name="format">
            <xsl:call-template name="page.number.format">
              <xsl:with-param name="master-reference" select="$master-reference"/>
            </xsl:call-template>
          </xsl:attribute>
          <xsl:attribute name="initial-page-number">
            <xsl:call-template name="initial.page.number">
              <xsl:with-param name="master-reference" select="$master-reference"/>
            </xsl:call-template>
          </xsl:attribute>
          <xsl:attribute name="force-page-count">
            <xsl:call-template name="force.page.count">
              <xsl:with-param name="master-reference" select="$master-reference"/>
            </xsl:call-template>
          </xsl:attribute>
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
          
          <xsl:apply-templates select="." mode="running.head.mode">
            <xsl:with-param name="master-reference" select="$master-reference"/>
          </xsl:apply-templates>
          <xsl:apply-templates select="." mode="running.foot.mode">
            <xsl:with-param name="master-reference" select="$master-reference"/>
          </xsl:apply-templates>
          
          <fo:flow flow-name="xsl-region-body">
            <xsl:call-template name="set.flow.properties">
              <xsl:with-param name="element" select="local-name(.)"/>
              <xsl:with-param name="master-reference" select="$master-reference"/>
            </xsl:call-template>
            
            <!--BEGIN-EDIT-->
            <xsl:choose>
              <xsl:when test="ancestor-or-self::*[@revisionflag]">
                <xsl:variable name="class" select="generate-id()"/>
                <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
                  <!-- open a changebar here if we have set them to be on -->
                  <xsl:if test="$use.changebars != 0">
                    <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
                  </xsl:if>
                  <!-- insert the original content -->
                  <fo:block id="{$id}">
                    <xsl:call-template name="bibliography.titlepage"/>
                  </fo:block>
                  <xsl:apply-templates/>
                  <!-- end of original content -->
                  <!-- close the changebar here if we have set them to be on -->
                  <xsl:if test="$use.changebars != 0">
                    <fo:change-bar-end change-bar-class="{$class}"/>
                  </xsl:if>
                </fo:block>
              </xsl:when>
              <xsl:otherwise>
                <!--END-EDIT-->
                <fo:block id="{$id}">
                  <xsl:call-template name="bibliography.titlepage"/>
                </fo:block>
                <xsl:apply-templates/>
                <!--BEGIN-EDIT-->
              </xsl:otherwise>
            </xsl:choose>
            <!--END-EDIT-->
            
          </fo:flow>
        </fo:page-sequence>
      </xsl:when>
      <xsl:otherwise>
        <!--BEGIN-EDIT-->
        <xsl:choose>
          <xsl:when test="ancestor-or-self::*[@revisionflag]">
            <xsl:variable name="class" select="generate-id()"/>
            <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
              <!-- open a changebar here if we have set them to be on -->
              <xsl:if test="$use.changebars != 0">
                <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
              </xsl:if>
              <!-- insert the orginal content -->
              <fo:block id="{$id}"
                space-before.minimum="1em"
                space-before.optimum="1.5em"
                space-before.maximum="2em">
                <xsl:call-template name="bibliography.titlepage"/>
              </fo:block>
              <xsl:apply-templates/>
              <!-- end of original content -->
              <!-- close the changebar here if we have set them to be on -->
              <xsl:if test="$use.changebars != 0">
                <fo:change-bar-end change-bar-class="{$class}"/>
              </xsl:if>
            </fo:block>
          </xsl:when>
          <xsl:otherwise>
            <!--END-EDIT-->
            <fo:block id="{$id}"
              space-before.minimum="1em"
              space-before.optimum="1.5em"
              space-before.maximum="2em">
              <xsl:call-template name="bibliography.titlepage"/>
            </fo:block>
            <xsl:apply-templates/>
            <!--BEGIN-EDIT-->
          </xsl:otherwise>
        </xsl:choose>
        <!--END-EDIT-->
        
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <!-- need to override this as a colophon starts a new page sequence which cannot be surrounded by an fo:block-->
  <!-- original template from fo/component.xsl -->
  <!-- slight modification from previous docbook-changebars-0.1.2 release -->
  <xsl:template match="d:colophon">
    <xsl:variable name="id">
      <xsl:call-template name="object.id"/>
    </xsl:variable>
    
    <xsl:variable name="master-reference">
      <xsl:call-template name="select.pagemaster"/>
    </xsl:variable>
    
    <fo:page-sequence hyphenate="{$hyphenate}"
      master-reference="{$master-reference}">
      <xsl:attribute name="language">
        <xsl:call-template name="l10n.language"/>
      </xsl:attribute>
      <xsl:attribute name="format">
        <xsl:call-template name="page.number.format">
          <xsl:with-param name="master-reference" select="$master-reference"/>
        </xsl:call-template>
      </xsl:attribute>
      <xsl:attribute name="initial-page-number">
        <xsl:call-template name="initial.page.number">
          <xsl:with-param name="master-reference" select="$master-reference"/>
        </xsl:call-template>
      </xsl:attribute>
      <xsl:attribute name="force-page-count">
        <xsl:call-template name="force.page.count">
          <xsl:with-param name="master-reference" select="$master-reference"/>
        </xsl:call-template>
      </xsl:attribute>
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
      
      <xsl:apply-templates select="." mode="running.head.mode">
        <xsl:with-param name="master-reference" select="$master-reference"/>
      </xsl:apply-templates>
      
      <xsl:apply-templates select="." mode="running.foot.mode">
        <xsl:with-param name="master-reference" select="$master-reference"/>
      </xsl:apply-templates>
      
      <fo:flow flow-name="xsl-region-body">
        <xsl:call-template name="set.flow.properties">
          <xsl:with-param name="element" select="local-name(.)"/>
          <xsl:with-param name="master-reference" select="$master-reference"/>
        </xsl:call-template>
        
        <!--BEGIN-EDIT-->
        <xsl:choose>
          <xsl:when test="ancestor-or-self::*[@revisionflag]">
            <xsl:variable name="class" select="generate-id()"/>
            <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
              <!-- open a changebar here if we have set them to be on -->
              <xsl:if test="$use.changebars != 0">
                <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
              </xsl:if>
              <!-- insert the orginal content -->
              <fo:block id="{$id}"
                        xsl:use-attribute-sets="component.titlepage.properties">
                <xsl:call-template name="colophon.titlepage"/>
              </fo:block>
              <xsl:apply-templates/>
              <!-- end of original content -->
              <!-- close the changebar here if we have set them to be on -->
              <xsl:if test="$use.changebars != 0">
                <fo:change-bar-end change-bar-class="{$class}"/>
              </xsl:if>
            </fo:block>
          </xsl:when>
          <xsl:otherwise>
            <!--END-EDIT-->
            <fo:block id="{$id}"
                      xsl:use-attribute-sets="component.titlepage.properties">
              <xsl:call-template name="colophon.titlepage"/>
            </fo:block>
            <xsl:apply-templates/>
            <!--BEGIN-EDIT-->
          </xsl:otherwise>
        </xsl:choose>
        <!--END-EDIT-->
        
        
      </fo:flow>
    </fo:page-sequence>
  </xsl:template>
  
  <!-- need to override this template so that bullets (or other labels) on added or deleted listitems are coloured -->
  <!-- orinally from fo/lists.xml -->
  <xsl:template name="itemizedlist.label.markup">
    <xsl:param name="itemsymbol" select="'disc'"/>
    
    <xsl:variable name="label">
      <xsl:choose>
        <xsl:when test="$itemsymbol='none'"></xsl:when>
        <xsl:when test="$itemsymbol='disc'">&#x2022;</xsl:when>
        <xsl:when test="$itemsymbol='bullet'">&#x2022;</xsl:when>
        <xsl:when test="$itemsymbol='endash'">&#x2013;</xsl:when>
        <xsl:when test="$itemsymbol='emdash'">&#x2014;</xsl:when>
        <!-- Some of these may work in your XSL-FO processor and fonts -->
        <!--
          <xsl:when test="$itemsymbol='square'">&#x25A0;</xsl:when>
          <xsl:when test="$itemsymbol='box'">&#x25A0;</xsl:when>
          <xsl:when test="$itemsymbol='smallblacksquare'">&#x25AA;</xsl:when>
          <xsl:when test="$itemsymbol='circle'">&#x25CB;</xsl:when>
          <xsl:when test="$itemsymbol='opencircle'">&#x25CB;</xsl:when>
          <xsl:when test="$itemsymbol='whitesquare'">&#x25A1;</xsl:when>
          <xsl:when test="$itemsymbol='smallwhitesquare'">&#x25AB;</xsl:when>
          <xsl:when test="$itemsymbol='round'">&#x25CF;</xsl:when>
          <xsl:when test="$itemsymbol='blackcircle'">&#x25CF;</xsl:when>
          <xsl:when test="$itemsymbol='whitebullet'">&#x25E6;</xsl:when>
          <xsl:when test="$itemsymbol='triangle'">&#x2023;</xsl:when>
          <xsl:when test="$itemsymbol='point'">&#x203A;</xsl:when>
          <xsl:when test="$itemsymbol='hand'"><fo:inline 
          font-family="Wingdings 2">A</fo:inline></xsl:when>
        -->
        <xsl:otherwise>&#x2022;</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <xsl:variable name="class" select="generate-id()"/>
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:copy-of select="$label"/>
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:copy-of select="$label"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  
  <!-- need to override this template so that numbers on added or deleted listitems are coloured -->
  <!-- orinally from fo/lists.xml -->
  <!-- cannot located in 1.74.0 because moved to common-->
  <!--

  <xsl:template match="orderedlist/listitem" mode="item-number">
    <xsl:variable name="numeration">
      <xsl:call-template name="list.numeration">
        <xsl:with-param name="node" select="parent::orderedlist"/>
      </xsl:call-template>
    </xsl:variable>
    
    <xsl:variable name="type">
      <xsl:choose>
        <xsl:when test="$numeration='arabic'">1.</xsl:when>
        <xsl:when test="$numeration='loweralpha'">a.</xsl:when>
        <xsl:when test="$numeration='lowerroman'">i.</xsl:when>
        <xsl:when test="$numeration='upperalpha'">A.</xsl:when>
        <xsl:when test="$numeration='upperroman'">I.</xsl:when>
        <xsl:otherwise>
          <xsl:message>
            <xsl:text>Unexpected numeration: </xsl:text>
            <xsl:value-of select="$numeration"/>
          </xsl:message>
          <xsl:value-of select="1."/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    
    <xsl:variable name="item-number">
      <xsl:call-template name="orderedlist-item-number"/>
    </xsl:variable>
    
    <xsl:if test="parent::orderedlist/@inheritnum='inherit'
      and ancestor::listitem[parent::orderedlist]">
      <xsl:apply-templates select="ancestor::listitem[parent::orderedlist][1]"
        mode="item-number"/>
    </xsl:if>
    
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:number value="$item-number" format="{$type}"/>
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:number value="$item-number" format="{$type}"/>
      </xsl:otherwise>
    </xsl:choose>
    
  </xsl:template>
-->

  <!-- orinally from fo/lists.xml -->
  <!-- new in docbook-changebars-0.1.3 -->
  <xsl:template match="d:orderedlist/d:listitem">
    <xsl:variable name="id"><xsl:call-template name="object.id"/></xsl:variable>
    <xsl:variable name="class" select="generate-id()"/>  <!-- added line -->
    <xsl:variable name="item.contents">
      <fo:list-item-label end-indent="label-end()" xsl:use-attribute-sets="orderedlist.label.properties">
        <xsl:choose> <!-- added line -->
          <xsl:when test="ancestor-or-self::*[@revisionflag]"> <!-- added line -->
            <fo:block xsl:use-attribute-sets="ancestor.revision.atts"> <!-- modified line - added @xsl:use-attribute-sets -->
              <xsl:if test="$use.changebars != 0"> <!-- added line -->
                <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/> <!-- added line -->
              </xsl:if> <!-- added line -->
              <xsl:apply-templates select="." mode="item-number"/>
              <xsl:if test="$use.changebars != 0"> <!-- added line -->
                <fo:change-bar-end change-bar-class="{$class}"/> <!-- added line -->
              </xsl:if> <!-- added line -->
            </fo:block>
          </xsl:when> <!-- added line -->
          <xsl:otherwise> <!-- added line -->
            <fo:block>
              <xsl:apply-templates select="." mode="item-number"/>
            </fo:block>
          </xsl:otherwise> <!-- added line -->
        </xsl:choose> <!-- added line -->
      </fo:list-item-label>
      <fo:list-item-body start-indent="body-start()">
        <fo:block>
          <xsl:apply-templates/>
        </fo:block>
      </fo:list-item-body>
    </xsl:variable>

    <xsl:choose>
      <xsl:when test="parent::*/@spacing = 'compact'">
        <fo:list-item id="{$id}" xsl:use-attribute-sets="compact.list.item.spacing">
          <xsl:copy-of select="$item.contents"/>
        </fo:list-item>
      </xsl:when>
      <xsl:otherwise>
        <fo:list-item id="{$id}" xsl:use-attribute-sets="list.item.spacing">
          <xsl:copy-of select="$item.contents"/>
        </fo:list-item>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  
  <!-- this template need to be overridden because it is a named template -->
  <!-- originally from fo/footnote.xsl -->
  <xsl:template name="format.footnote.mark">
    <xsl:param name="mark" select="'?'"/>
    <xsl:variable name="class" select="generate-id()"/>
    <fo:inline xsl:use-attribute-sets="footnote.mark.properties ancestor.revision.atts">
      <xsl:choose>
        <xsl:when test="$fop.extensions != 0">
          <xsl:attribute name="vertical-align">super</xsl:attribute>
        </xsl:when>
        <xsl:otherwise>
          <xsl:attribute name="baseline-shift">super</xsl:attribute>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:if test="$use.changebars != 0 and @revisionflag">
        <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
      </xsl:if>
      <xsl:copy-of select="$mark"/>
      <xsl:if test="$use.changebars != 0 and @revisionflag">
        <fo:change-bar-end change-bar-class="{$class}"/>
      </xsl:if>
    </fo:inline>
  </xsl:template>  
  
  <!-- originally from fo/xref.xsl -->
  <!-- modified from previous docbook-changebars-0.1.2 
       to reflect changes in docbook-xsl-1.74.0 -->
  <xsl:template match="ulink" name="ulink">
    <xsl:param name="url" select="@url"/>
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:variable name ="ulink.url">
      <xsl:call-template name="fo-external-image">
        <xsl:with-param name="filename" select="$url"/>
      </xsl:call-template>
    </xsl:variable>

    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:basic-link xsl:use-attribute-sets="xref.properties ancestor.revision.atts"
                       external-destination="{$ulink.url}">
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:choose>
            <xsl:when test="count(child::node())=0">
              <xsl:call-template name="hyphenate-url">
                <xsl:with-param name="url" select="$url"/>
              </xsl:call-template>
              </xsl:when>
              <xsl:otherwise>
                <xsl:apply-templates/>
              </xsl:otherwise>
          </xsl:choose>
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:basic-link>
      </xsl:when>
      <xsl:otherwise>
        <fo:basic-link xsl:use-attribute-sets="xref.properties"
                       external-destination="{$ulink.url}">
          <xsl:choose>
            <xsl:when test="count(child::node())=0">
              <xsl:call-template name="hyphenate-url">
                <xsl:with-param name="url" select="$url"/>
              </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
              <xsl:apply-templates/>
            </xsl:otherwise>
          </xsl:choose>
        </fo:basic-link>
      </xsl:otherwise>
    </xsl:choose>
    <!-- * Call the template for determining whether the URL for this -->
    <!-- * hyperlink is displayed, and how to display it (either inline or -->
    <!-- * as a numbered footnote). -->
    <xsl:call-template name="hyperlink.url.display">
      <xsl:with-param name="url" select="$url"/>
      <xsl:with-param name="ulink.url" select="$ulink.url"/>
    </xsl:call-template>
  </xsl:template>

</xsl:stylesheet>