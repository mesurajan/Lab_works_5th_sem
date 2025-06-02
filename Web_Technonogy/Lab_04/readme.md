Lab Questions for Unit IV: AJAX and XML

1. AJAX Basics
**Question**:  
Write a simple web page that uses AJAX to fetch and display a text file’s content (`data.txt`) when a button is clicked. The text file should contain a short message (e.g., "Hello from the server!").

**What to Do**:  
- Create an HTML file with a button and a `<div>` to show the result.  
- Use `XMLHttpRequest` in JavaScript to fetch `data.txt`.  
- Display the text in the `<div>`.

**Sample Starter**:  
```html
<html>
<body>
    <button onclick="fetchData()">Get Message</button>
    <div id="result"></div>
    <script>
        function fetchData() {
            let xhr = new XMLHttpRequest();
            xhr.open("GET", "data.txt", true);
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById("result").innerHTML = xhr.responseText;
                }
            };
            xhr.send();
        }
    </script>
</body>
</html>
```
**Tip**: Create `data.txt` with a simple message. Test it on a local server (e.g., XAMPP) since AJAX needs a server to work.

---

#### 2. XML Syntax and Structure
**Question**:  
Create an XML file to store details of 3 books (title, author, price). Ensure it follows XML syntax rules (root element, proper nesting, closed tags). Then, validate it using an online XML validator.

**What to Do**:  
- Write the XML with a root `<library>` and 3 `<book>` elements.  
- Check it online (e.g., xmlvalidation.com).

**Sample Answer**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<library>
    <book>
        <title>Web Tech</title>
        <author>John Doe</author>
        <price>25</price>
    </book>
    <book>
        <title>PHP Basics</title>
        <author>Jane Smith</author>
        <price>30</price>
    </book>
    <book>
        <title>XML Guide</title>
        <author>Sam Lee</author>
        <price>20</price>
    </book>
</library>
```
**Tip**: Double-check nesting and closing tags—easy points to lose!

---

#### 3. XML with Namespace
**Question**:  
Write an XML file that uses two namespaces to represent a school and a store. Include one `<item>` for the school (e.g., a student) and one for the store (e.g., a product). Use prefixes to avoid tag conflicts.

**What to Do**:  
- Declare two namespaces with `xmlns:prefix`.  
- Use different prefixes for school and store tags.

**Sample Answer**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<root xmlns:sch="http://example.com/school" xmlns:sto="http://example.com/store">
    <sch:item>
        <sch:name>John</sch:name>
        <sch:grade>A</sch:grade>
    </sch:item>
    <sto:item>
        <sto:name>Laptop</sto:name>
        <sto:price>800</sto:price>
    </sto:item>
</root>
```
**Tip**: Test with a validator to ensure the namespaces are recognized. Think about why `<sch:name>` and `<sto:name>` don’t clash.

---

#### 4. DTD Validation
**Question**:  
Create an XML file for a classroom with at least 2 students (name, age). Write an internal DTD to define the structure, requiring an `id` attribute for each student. Validate the XML.

**What to Do**:  
- Write the XML with an internal `<!DOCTYPE>` section.  
- Define elements and the `id` attribute.

**Sample Answer**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE classroom [
    <!ELEMENT classroom (student+)>
    <!ELEMENT student (name, age)>
    <!ELEMENT name (#PCDATA)>
    <!ELEMENT age (#PCDATA)>
    <!ATTLIST student id CDATA #REQUIRED>
]>
<classroom>
    <student id="S01">
        <name>John</name>
        <age>20</age>
    </student>
    <student id="S02">
        <name>Mary</name>
        <age>21</age>
    </student>
</classroom>
```
**Tip**: Try an external DTD too (save as `classroom.dtd` and link with `SYSTEM "classroom.dtd"`). Validate online to confirm.

---

#### 5. XSD with Elements and Attributes
**Question**:  
Write an XSD file to define a `<course>` element that contains multiple `<student>` elements. Each `<student>` must have a `<name>` (string), `<age>` (integer), and a required `id` attribute. Create a matching XML file.

**What to Do**:  
- Use `<xs:element>` and `<xs:complexType>` in the XSD.  
- Add an `<xs:attribute>` for `id`.  
- Write a small XML to test it.

**Sample XSD**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xs:element name="course">
        <xs:complexType>
            <xs:sequence>
                <xs:element name="student" maxOccurs="unbounded">
                    <xs:complexType>
                        <xs:sequence>
                            <xs:element name="name" type="xs:string"/>
                            <xs:element name="age" type="xs:integer"/>
                        </xs:sequence>
                        <xs:attribute name="id" type="xs:string" use="required"/>
                    </xs:complexType>
                </xs:element>
            </xs:sequence>
        </xs:complexType>
    </xs:element>
</xs:schema>
```
**Sample XML**:  
```xml
<course>
    <student id="S01">
        <name>John</name>
        <age>20</age>
    </student>
    <student id="S02">
        <name>Mary</name>
        <age>21</age>
    </student>
</course>
```
**Tip**: Use an online validator to check if the XML fits the XSD. Try removing `id` to see it fail!

---

#### 6. XSD with Restrictions
**Question**:  
Create an XSD for a `<product>` element with `<name>` (string, 3-20 characters), `<price>` (integer, 10-1000), and an optional `category` attribute. Write a matching XML file.

**What to Do**:  
- Use `<xs:restriction>` for `<name>` and `<price>`.  
- Add an optional `<xs:attribute>`.

**Sample XSD**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xs:element name="product">
        <xs:complexType>
            <xs:sequence>
                <xs:element name="name">
                    <xs:simpleType>
                        <xs:restriction base="xs:string">
                            <xs:minLength value="3"/>
                            <xs:maxLength value="20"/>
                        </xs:restriction>
                    </xs:simpleType>
                </xs:element>
                <xs:element name="price">
                    <xs:simpleType>
                        <xs:restriction base="xs:integer">
                            <xs:minInclusive value="10"/>
                            <xs:maxInclusive value="1000"/>
                        </xs:restriction>
                    </xs:simpleType>
                </xs:element>
            </xs:sequence>
            <xs:attribute name="category" type="xs:string" use="optional"/>
        </xs:complexType>
    </xs:element>
</xs:schema>
```
**Sample XML**:  
```xml
<product category="Electronics">
    <name>Laptop</name>
    <price>800</price>
</product>
```
**Tip**: Test with `<price>5</price>` (should fail) or `<name>Hi</name>` (too short).

---

#### 7. XSD with Complex Types
**Question**:  
Design an XSD for a `<team>` element that has multiple `<member>` elements. Each `<member>` must have `<name>` and either `<role>` or `<skill>` (not both). Create a valid XML file.

**What to Do**:  
- Use `<xs:complexType>` with `<xs:choice>` for the either/or part.

**Sample XSD**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xs:element name="team">
        <xs:complexType>
            <xs:sequence>
                <xs:element name="member" maxOccurs="unbounded">
                    <xs:complexType>
                        <xs:sequence>
                            <xs:element name="name" type="xs:string"/>
                            <xs:choice>
                                <xs:element name="role" type="xs:string"/>
                                <xs:element name="skill" type="xs:string"/>
                            </xs:choice>
                        </xs:sequence>
                    </xs:complexType>
                </xs:element>
            </xs:sequence>
        </xs:complexType>
    </xs:element>
</xs:schema>
```
**Sample XML**:  
```xml
<team>
    <member>
        <name>John</name>
        <role>Leader</role>
    </member>
    <member>
        <name>Mary</name>
        <skill>Coding</skill>
    </member>
</team>
```
**Tip**: Try adding both `<role>` and `<skill>` to one `<member>`—it should fail validation.

---

#### 8. XSLT Transformation
**Question**:  
Write an XML file with 2 students (name, grade). Create an XSLT file to transform it into an HTML table. Display the result in a browser.

**What to Do**:  
- Write the XML and XSLT.  
- Link them with `<?xml-stylesheet>`.

**Sample XML (`students.xml`)**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="students.xsl"?>
<students>
    <student>
        <name>John</name>
        <grade>A</grade>
    </student>
    <student>
        <name>Mary</name>
        <grade>B</grade>
    </student>
</students>
```
**Sample XSLT (`students.xsl`)**:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>
                <table border="1">
                    <tr>
                        <th>Name</th>
                        <th>Grade</th>
                    </tr>
                    <xsl:for-each select="students/student">
                        <tr>
                            <td><xsl:value-of select="name"/></td>
                            <td><xsl:value-of select="grade"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
```
**Tip**: Open `students.xml` in a browser to see the table. Tweak the XSLT to add colors or headers!

---

#### 9. XQuery Search
**Question**:  
Create an XML file with 3 products (name, price). Write an XQuery to find products with a price less than 50. Show the results.

**What to Do**:  
- Write the XML.  
- Use an XQuery tool (e.g., online sandbox) to run it.

**Sample XML (`products.xml`)**:  
```xml
<products>
    <product>
        <name>Book</name>
        <price>25</price>
    </product>
    <product>
        <name>Laptop</name>
        <price>800</price>
    </product>
    <product>
        <name>Pen</name>
        <price>10</price>
    </product>
</products>
```
**Sample XQuery**:  
```xquery
for $p in doc("products.xml")/products/product
where $p/price < 50
return $p/name
```
**Expected Output**:  
```
Book
Pen
```
**Tip**: If you don’t have a tool, write the query and explain it—shows you get the logic!