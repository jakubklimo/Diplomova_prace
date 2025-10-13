#import "../lang.typ": get_lang_item
#import "common.typ": (
  mainpage,
  default_styling,
  assignment,
  disclaimer,
  abstract,
  toc,
  abbrlist,
  imagelist,
  tablelist,
  bibliogr,
)
#import "../attachments.typ": attachment_list
#import "../utils.typ": is_none, assert_not_none, assert_dict_has, assert_in_arr

#let other(
  // general settings
  faculty_id, faculty_color, language, assignment_document, citation_file,

  // document info
  title, author, _, supervisor, consultant, study_programme, study_specialization, year_of_study,
  abstract_content, _, keywords,

  content
) = {
  assert_not_none(title, "title");
  assert_dict_has((language,), title, "title");

  mainpage(
    faculty_id, language, none, title, author, supervisor, consultant, study_programme,
    study_specialization, year_of_study,
  );
  default_styling(true, faculty_color, {
    toc(language);
    tablelist(language);
    imagelist(language);
    abbrlist(language);
    pagebreak(to: "even", weak: true);
    content;
    bibliogr(language, citation_file);
    attachment_list(language);
  });
}
