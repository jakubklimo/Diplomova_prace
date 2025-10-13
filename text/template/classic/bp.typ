#import "../lang.typ": get_lang_item
#import "common.typ": (
  mainpage,
  default_styling,
  assignment,
  disclaimer,
  abstract,
  acknowledgement,
  toc,
  abbrlist,
  imagelist,
  tablelist,
  bibliogr
)
#import "../attachments.typ": attachment_list
#import "../utils.typ": is_none, assert_dict_has, assert_not_none, assert_type_signature

#let bp(
  // general settings
  faculty_id, faculty_color, language, assignment_document, citation_file,

  // document info
  title, author, author_pronouns, supervisor, consultant, study_programme, study_specialization,
  year_of_study, abstract_content, acknowledgement_content, keywords,

  content
) = {
  let force_langs = ("cs", "en");
  assert_not_none(title, "title");
  assert_dict_has(force_langs, title, "title");

  assert_not_none(study_programme, "study programme");
  assert_dict_has((language,), study_programme, "study programme");
  assert_not_none(study_specialization, "study specialization");
  assert_dict_has((language,), study_specialization, "study specialization");

  assert_not_none(abstract_content, "abstract");
  assert_dict_has(force_langs, abstract_content, "abstract");
  if not is_none(keywords) {
    assert_dict_has(force_langs, keywords, "keywords");
  }
  if language == "cs" {
    assert_not_none(author_pronouns, "author gender");
  }

  assert_type_signature(supervisor, "string | none", "supervisor");
  assert_type_signature(consultant, "string | none", "consultant");

  mainpage(
    faculty_id, language, "bp", title, author, supervisor, consultant, study_programme,
    study_specialization, year_of_study,
  );
  assignment(language, assignment_document);
  default_styling(false, faculty_color, {
    disclaimer(language, faculty_id, "bp", author, author_pronouns);
    if language == "cs" {
      abstract("cs", title, abstract_content, keywords);
      abstract("en", title, abstract_content, keywords);
    }
    if language == "en" {
      abstract("en", title, abstract_content, keywords);
      abstract("cs", title, abstract_content, keywords);
    }
    acknowledgement(language, author, acknowledgement_content);
    toc(language);
    tablelist(language);
    imagelist(language);
    abbrlist(language);
    pagebreak(weak: true);
    content;
    bibliogr(language, citation_file);
    attachment_list(language);
  });
}
