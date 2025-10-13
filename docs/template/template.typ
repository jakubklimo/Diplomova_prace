// +---------------+
// | TULTemplate 2 |
// +---------------+
//
// Unofficial TUL template for all kinds of documents.
//
// Git: https://git.zumepro.cz/tul/tultemplate2

#import "prototyping.typ": todo, profile
#import "attachments.typ": (
  attachments, attach_content, attach_pdf, attach_link, attach_file_reference
)

// TUL Template 2
//
// Use this at the beginning of a Typst file:
// ```typst
// #import "template/template.typ": *
//
// #show: tultemplate2.with(
//   "classic", "fm", "cs", ...
// )
// ```
//
// - style (str): Visual style to use. This can be "classic".
// - faculty (str): Factulty abbreviation. One of "fs", "ft", "fp", "ef", "fua", "fm", "fzs", "cxi".
// - lang (str): Language code. This can be "cs" or "en".
// - document (str): Type of document. This can be "bp" or "other".
// - title (dictionary): The title of the document.
// - author (str): The name of the document's author.
// - author_pronouns (str): The gender of the document's author. Needed only for the `cs` language.
// - supervisor (str): The name of the document's supervisor.
// - consultant (str): The name of the document's consultant.
// - programme (dictionary): Study programme.
// - specialization (disctionary): Study specialization
// - abstract (dictionary): The abstract.
// - keywords (dictionary): The abstract keywords.
// - assignment (str): Filepath of the assignment document/page.
// - citations (str): The location of the citation file.
// - content (content): The content of the document
//
//-> none
#let tultemplate2(
  // general settings
  style: "classic", faculty: "fm", lang: "cs", document: "dp",

  // document info
  title: none, keywords: none, abstract: none, acknowledgement: none, author: none,
  author_pronouns: none, supervisor: none, consultant: none, programme: none,
  specialization: none, year_of_study: none,

  // links
  assignment: none, citations: "citations.bib",

  // content
  content,
) = {
  import "utils.typ": assert_in_dict, assert_type_signature

  // argument checking
  assert_type_signature(style, "string", "visual style argument");
  assert_type_signature(faculty, "string", "faculty id argument");
  assert_type_signature(lang, "string", "language abbreviation argument");
  assert_type_signature(document, "string | none", "document kind argument");
  assert_type_signature(title, "dictionary[string : string] | none", "title argument");
  assert_type_signature(keywords, "dictionary[string : array[string]] | none", "keywords argument");
  assert_type_signature(
    abstract, "dictionary[string : string | content] | none", "abstract argument"
  );
  assert_type_signature(
    acknowledgement, "dictionary[string : string | content] | none", "acknowledgement content"
  );
  assert_type_signature(author, "string | none", "author argument");
  assert_type_signature(author_pronouns, "string | none", "author gender argument");
  assert_type_signature(
    supervisor, "string | dictionary[string : string] | none", "supervisor argument"
  );
  assert_type_signature(
    consultant, "string | dictionary[string : string] | none", "consultant argument"
  );
  assert_type_signature(
    programme, "dictionary[string : string] | none", "study programme argument"
  );
  assert_type_signature(
    specialization, "dictionary[string : string] | none", "study specialization argument"
  );
  assert_type_signature(year_of_study, "integer | none", "year of study");
  assert_type_signature(assignment, "string | none", "assignment document argument");
  assert_type_signature(citations, "string", "citations file argument");

  // templates
  import "classic/classic.typ": template_classic
  let templates = (
    classic: template_classic,
  );
  assert_in_dict(style, templates, "template name");

  // language set-up
  import "lang.typ": lang_ids
  assert_in_dict(lang, lang_ids, "language abbreviation");
  set text(lang: lang);

  // template call
  templates.at(style)(
    lang, faculty, document, citations, assignment,
    title, author, author_pronouns, supervisor, consultant,
    programme, specialization, year_of_study, abstract, acknowledgement, keywords, content
  );

  import "prototyping.typ": assert_release_ready
  assert_release_ready();
}

// Make a new abbreviation
//
// - abbreviation (str): The abbreviation
// - text (str): Optionally, the text - the meaning of the abbreviation.
#let abbr(abbreviation, ..text) = {
  import "abbreviations.typ": abbr
  return abbr(abbreviation, if text.pos().len() == 0 { none } else { text.pos().at(0) });
}
